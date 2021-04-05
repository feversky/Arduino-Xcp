#include "XcpSxIMaster.h"
#include "XcpBasic.h"
#include "Arduino.h"

#define SLIP_SYNC 0x9A
#define SLIP_ESC  0x9B
#define ESC_SYNC  1
#define ESC_ESC   0


XcpSxIMaster::XcpSxIMaster(unsigned long baudrate)
{
    baudrate = baudrate;
    Serial.begin(baudrate);
}

void XcpSxIMaster::Init()
{
    XcpInit();
}

void XcpSxIMaster::Event(unsigned char event)
{
    XcpEvent(event);
}

void XcpSxIMaster::BackgroudTask()
{
    static char bOld;
    static bool sync = false;

    while (Serial.available())
    {
        char b = Serial.read();
        // SlipMode
        // A new packet always starts with a SYNC
        if (!sync)
        {
            if (b < 0)
                continue;
            if (b != SLIP_SYNC)
                continue; // Skip this byte
            sync = 1;
            bufIdx = 0;
            bOld = 0;
        }
        else
        {
            if (b == SLIP_SYNC)
            {
                sync = 1;
                bufIdx = 0;
                bOld = 0;
                continue; // SYNC shall be replaced by ESC+ESC_SYNC
            }
            else if (bOld == SLIP_ESC)
            {
                bOld = 0;        
                if (b == ESC_SYNC)
                {
                    buf[bufIdx] = SLIP_SYNC;
                    bufIdx++;
                }
                else if (b == ESC_ESC)
                {
                    buf[bufIdx] = SLIP_ESC;
                    bufIdx++;
                }
                else
                {
                    // it's wrong, discard entire packet
                    sync = 0;
                    bufIdx = 0;
                }
                continue;         
            }
            else if ((b == SLIP_ESC) && (bufIdx > 0) && (bufIdx <= buf[0] + 1))
            {
                // framing machanism only used in data field
                bOld = b;
                continue;
            }
            else
            {
                // Save this byte
                buf[bufIdx] = b;
                unsigned char len = buf[0]; // buf[0] always is the packet length
                bufIdx++;
                
                // Check if this is a valid packet
                if (len == 0)
                {
                    sync = 0;
                    bufIdx = 0;
                }

                // Check if the packet is complete
                if (bufIdx <= len + 1)
                {
                    continue;
                }
                
                // Verify checksum
                unsigned char cs = len;
                for (unsigned char i = 0; i < len; i++)
                    cs += buf[i + 1];
                if (cs != buf[bufIdx - 1])
                { 
                    // Checksum error
                    sync = 0;
                    bufIdx = 0;
                    continue;
                }

                // Return the packet
                sync = 0;
                bufIdx = 0;
                XcpCommand((unsigned long *)&buf[1]);
            }
        }
    }

    XcpBackground();
    XcpSendCallBack();
}

extern "C"
{

unsigned char TransmitSlipByte(unsigned char b) 
{  
    /* NOTE: If the transmit buffer is full then Serial.write() will block until there is enough space in the buffer.*/
    switch (b) 
    {
        case SLIP_ESC:  
            return Serial.write(SLIP_ESC) && Serial.write(0x00);
        case SLIP_SYNC: 
            return Serial.write(SLIP_ESC) && Serial.write(0x01);
        default: 
            return Serial.write(b);
    }
}

// Transmit a XCP packet
// Called by the XCP driver
void ApplXcpSend(unsigned char len, const unsigned char * pMsg) 
{
    unsigned char b, checksum, i, len1;
    const unsigned char * pData = pMsg;
    if (len==0||len>kXcpMaxDTO) return; // should not happen
    if (!Serial.write(SLIP_SYNC)) return; // Each packet begins with SYNC

    len1 = len;
    for (i = 0; i < len; i++)
    {
        b = *pData++;
        if (b == SLIP_SYNC || b == SLIP_ESC)
        {
            len1++;
        }
    }

    if (!Serial.write(len1)) return;

    checksum = len1;
    while (len--) 
    {
        b = *pMsg++;
        switch (b)
        {
        case SLIP_SYNC:
            checksum += SLIP_ESC + ESC_SYNC;
            break;
        case SLIP_ESC:
            checksum += SLIP_ESC + ESC_ESC;
            break;
        default:
            checksum += b;
            break;
        }
        if (!TransmitSlipByte(b)) return;   
    }
    if (!Serial.write(checksum)) return;   

    return;       
}

//------------------------------------------------------------------------------
// Platform dependend functions

// Convert a XCP address to a pointer
unsigned char * ApplXcpGetPointer(unsigned char addr_ext, unsigned long addr) 
{
    addr_ext = addr_ext;
    return (unsigned char *)addr;
}

}
