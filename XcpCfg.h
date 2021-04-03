/*----------------------------------------------------------------------------
| Project: XCP_Delivery
|
|  Description:   Implementation of the XCP Protocol Layer
|                 XCP V1.0 slave device driver
|                 Basic Version
|
|-----------------------------------------------------------------------------
| Copyright (c) by Vector Informatik GmbH.  All rights reserved.
----------------------------------------------------------------------------*/

#if !defined(__XCP_CFG_H__)
#define __XCP_CFG_H__

#include "Arduino.h"

/* define here configuration parameters for customizing XcpBasic driver */

#ifdef __cplusplus
extern "C" {
#endif
	
#define vuint8 unsigned char /* Unsigned 8-bit identifier */
#define vuint16 unsigned short /* Unsigned 16-bit identifier */
#define vuint32 unsigned long /* Unsigned 32-bit identifier */

/* ROM memory qualifiers */
#if !defined(MEMORY_ROM)
  #define MEMORY_ROM const
#endif
#if !defined(V_MEMROM0)
  #define V_MEMROM0
#endif
#if !defined(MEMORY_CONST)
  #define MEMORY_CONST
#endif


/* General settings */

#define XCP_ENABLE_PARAMETER_CHECK
#define XCP_ENABLE_CALIBRATION
#define XCP_DISABLE_SEND_EVENT
#define XCP_DISABLE_TESTMODE
#define XCP_DISABLE_BOOTLOADER_DOWNLOAD
#define XCP_DISABLE_WRITE_PROTECTION
#define XCP_DISABLE_READ_PROTECTION
#define XCP_DISABLE_CONTROL
#define XCP_DISABLE_GET_XCP_DATA_POINTER
#define XCP_DISABLE_OPENCMDIF

#define XCP_CPUTYPE_LITTLEENDIAN

/* EEPROM access */
#define XCP_DISABLE_READ_EEPROM
#define XCP_DISABLE_WRITE_EEPROM

/* Service request message */
#define XCP_DISABLE_SERV_TEXT
#define XCP_DISABLE_SERV_TEXT_PUTCHAR
#define XCP_DISABLE_SERV_TEXT_PRINTF
#define XCP_DISABLE_SERV_TEXT_PRINT

/* Standard commands */
#define XCP_ENABLE_COMM_MODE_INFO
#define XCP_DISABLE_SEED_KEY
#define XCP_DISABLE_MODIFY_BITS
#define XCP_DISABLE_SHORT_DOWNLOAD
#define XCP_DISABLE_USER_COMMAND
#define XCP_DISABLE_VECTOR_MAPNAMES
#define XCP_DISABLE_TL_COMMAND

/* Block transfer */
#define XCP_DISABLE_BLOCK_UPLOAD
#define XCP_DISABLE_BLOCK_DOWNLOAD

/* Checksum */
#define XCP_DISABLE_CHECKSUM

/* Synchronous Data Acquisition (DAQ) */
#define XCP_ENABLE_DAQ
#define kXcpDaqMemSize                       256
#define XCP_DISABLE_STIM
#define XCP_DISABLE_UNALIGNED_MEM_ACCESS
#define XCP_ENABLE_SEND_QUEUE
#define XCP_DISABLE_DAQ_PRESCALER
#define XCP_ENABLE_DAQ_OVERRUN_INDICATION
#define XCP_DISABLE_WRITE_DAQ_MULTIPLE
#define XCP_DISABLE_DAQ_HDR_ODT_DAQ
#define XCP_DISABLE_DAQ_RESUME
#define XCP_ENABLE_DAQ_PROCESSOR_INFO
#define XCP_ENABLE_DAQ_RESOLUTION_INFO
#define XCP_SEND_QUEUE_SAMPLE_ODT

/* Events */
#define XCP_ENABLE_DAQ_EVENT_INFO

/* DAQ Timestamp */
#define XCP_DISABLE_DAQ_TIMESTAMP
#define XCP_DISABLE_DAQ_TIMESTAMP_FIXED

/* Page switching */
#define XCP_DISABLE_CALIBRATION_PAGE

/* Programming */
#define XCP_DISABLE_PROGRAM

#define CP_XCPDLL_VERSION                    0x0213u
#define CP_XCPDLL_RELEASE_VERSION            0x03u

/* Transport Layer */
#define kXcpNumberOfCanChannels              1
#define XCP_DISABLE_MULTI_CHANNEL
#define XCP_DISABLE_MULTI_CONNECTION_PROTECTION
#define XCP_TRANSPORT_LAYER_VERSION          0x0100u
#define XCP_DISABLE_VARIABLE_DLC
#define kXcpSendQueueMinSize                 1
// #define XCP_ENABLE_COMM_MODE_INFO
// #define XCP_DISABLE_USER_COMMAND
// #define XCP_DISABLE_BLOCK_UPLOAD
// #define XCP_DISABLE_SEND_EVENT
// #define XCP_DISABLE_SERV_TEXT
// #define XCP_DISABLE_SERV_TEXT_PRINT
// #define XCP_DISABLE_SERV_TEXT_PUTCHAR
// #define XCP_DISABLE_CALIBRATION_PAGE

// #define XCP_ENABLE_DAQ
// #define XCP_ENABLE_SEND_QUEUE
// #define XCP_ENABLE_DAQ_PROCESSOR_INFO
// #define XCP_ENABLE_DAQ_RESOLUTION_INFO
// #define XCP_DISABLE_DAQ_PRESCALER
// #define XCP_ENABLE_DAQ_OVERRUN_INDICATION
// #define XCP_DISABLE_DAQ_RESUME
// #define XCP_DISABLE_DAQ_HDR_ODT_DAQ


#define ApplXcpInterruptDisable noInterrupts
#define ApplXcpInterruptEnable interrupts
#define ApplXcpSendFlush()
#define ApplXcpBackground()

/* XCP message length */
#define kXcpMaxCTO     14      /* Maximum CTO Message Length */
#define kXcpMaxDTO     14      /* Maximum DTO Message Length */

#ifdef XCP_ENABLE_DAQ_EVENT_INFO
#define kXcpMaxEvent 2
extern vuint8 kXcpEventDirection[kXcpMaxEvent];
extern vuint8 kXcpEventNameLength[kXcpMaxEvent];
extern vuint8 kXcpEventCycle[kXcpMaxEvent];
extern vuint8 kXcpEventUnit[kXcpMaxEvent];
extern vuint8* kXcpEventName[kXcpMaxEvent];
#endif

#ifdef __cplusplus
}
#endif

#endif /* __XCP_CFG_H__ */
