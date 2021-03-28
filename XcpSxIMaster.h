#ifndef XCP_SXI_MASTER_H
#define XCP_SXI_MASTER_H

#include "XcpCfg.h"

class XcpSxIMaster
{
private:
    /* data */
    unsigned long baudrate;
    unsigned char buf[kXcpMaxCTO+2]; // + Header + Checksum
    unsigned char bufIdx;

public:
    XcpSxIMaster(unsigned long baudrate);

    void Init();
    void Event(unsigned char event); 
    void BackgroudTask();
};

extern "C"
{

extern void ApplXcpSend(unsigned char len, const unsigned char * const pMsg);
extern unsigned char * ApplXcpGetPointer(unsigned char addr_ext, unsigned long addr);

}


#endif