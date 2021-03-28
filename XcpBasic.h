

/*****************************************************************************
| Project Name:   XCP Protocol Layer
|    File Name:   XcpBasic.h
|
|  Description:   Header of XCP Protocol Layer
|                 XCP V1.0 slave device driver
|                 Basic Version
|
|-----------------------------------------------------------------------------
|               D E M O
|-----------------------------------------------------------------------------
|
|       Please note, that the demo and example programs 
|       only show special aspects of the software. 
|       With regard to the fact that these programs are meant 
|       for demonstration purposes only,
|       Vector Informatik's liability shall be expressly excluded in cases 
|       of ordinary negligence, to the extent admissible by law or statute.
|
|-----------------------------------------------------------------------------
|               C O P Y R I G H T
|-----------------------------------------------------------------------------
| Copyright (c) 2017 by Vector Informatik GmbH.           All rights reserved.
|
|       This software is copyright protected and 
|       proporietary to Vector Informatik GmbH.
|       Vector Informatik GmbH grants to you only
|       those rights as set out in the license conditions.
|       All other rights remain with Vector Informatik GmbH.
| 
|       Diese Software ist urheberrechtlich geschuetzt. 
|       Vector Informatik GmbH raeumt Ihnen an dieser Software nur 
|       die in den Lizenzbedingungen ausdruecklich genannten Rechte ein.
|       Alle anderen Rechte verbleiben bei Vector Informatik GmbH.
|
|-----------------------------------------------------------------------------
|               A U T H O R   I D E N T I T Y
|-----------------------------------------------------------------------------
| Initials     Name                      Company
| --------     ---------------------     -------------------------------------
| Ds           Sven Deckardt             Vector Informatik GmbH
| Eta          Edgar Tongoona            Vector Informatik GmbH
| Hr           Andreas Herkommer         Vector Informatik GmbH
| Svh          Sven Hesselmann           Vector Informatik GmbH
| Tri          Frank Triem               Vector Informatik GmbH
| Za           Rainer Zaiser             Vector Informatik GmbH
| Ore          Oliver Reineke            Vector Informatik GmbH
| Bwr          Brandon Root              Vector CANtech
|-----------------------------------------------------------------------------
|               R E V I S I O N   H I S T O R Y
|-----------------------------------------------------------------------------
|  Date       Version  Author  Description
| ----------  -------  ------  -----------------------------------------------
| 2000-24-09  10        Ds     - New header description
| 2003-24-04  10        Ds     - Swap GET_SECTOR_INFO Mode and Number
| 2003-24-04  10        Ds     - Swap SET_SEGMENT_MODE Mode and Number
| 2003-25-04  10        Ds     - Swap GET_SEGMENT_INFO Mode and Number
| 2003-28-04  10        Ds     - GET_SEGMENT_MODE reserved position 1
| 2003-28-04  10        Ds     - GET_PAGE_INFO reserved position 1
| 2003-10-30  1.0.03    Ds     - Rename xcp20.h to xcpProf.h 
| 2003-11-20  1.01.00   Tri    Updated to PSC standard.
|                              MISRA rules applied.
|                              Minor changes.
| 2004-02-11  1.01.01   Ds,Tri Updated and adaption for CANape
|                              ESCAN00007511: Warning when compiling XCP.H
|                              ESCAN00007517: Compiler error when using a packet length of 253 bytes or greater
|                              ESCAN00007518: Seed & Key: reading of the unlock key not performed correctly
|                              ESCAN00007532: Division by zero in calculation of the queue size
|                              ESCAN00007533: Memory overflow check during memory allocation might not be detected.
| 2004-06-16  1.02.00   Tri    ESCAN00008482: Add user defined function to service GET_ID
| 2005-01-03  1.03.00   Tri,Za ESCAN00008009: Rename module versions according to PD_PSC_Development
|                              ESCAN00009121: Add copyright note
|                              ESCAN00009125: Remove defines for revision 18
|                              ESCAN00009127: Remove XCP_ENABLE_SEND_BUFFER
|                              ESCAN00009130: Add support for data stimulation (STIM)
|                              ESCAN00007824: Warning due to unreferenced label 'negative_response1'
|                              ESCAN00008012: Remove include definitions of the standard libraries within XCP Professional
|                              ESCAN00008015: Avoid usage of the test mode within XCP Professional
|                              ESCAN00008018: XCP module version in response of CC_GET_COMM_MODE_INFO corrected
|                              ESCAN00008004: Compiler error when block upload is enabled and block download is disabled
|                              ESCAN00008005: Resource bit for CAL/PAG always set in response upon CC_CONNECT
|                              ESCAN00009141: Compiler warnings while compilation with Tasking Compiler
|                              ESCAN00007823: Warning about unreferenced variable 'prescaler'
|                              ESCAN00008003: Compiler error when block download is disabled and Programming enabled
|                              ESCAN00008060: Issue in negative response of command BUILD_CHECKSUM
|                              ESCAN00008013: Checksum calculation wrong
|                              ESCAN00008072: Compiler warning in range check of defines
|                              ESCAN00007971: Implement and support 'session configuration id'
|                              ESCAN00008006: Page switching always enabled when programming is enabled.
|                              ESCAN00008010: Remove extern declaration for xcp struct
|                              ESCAN00009154: Update Seed & Key
|                              ESCAN00010703: PROGRAM size = 0 is valid
|                              ESCAN00008017: Rework of Flash Programming by Flash Kernel
|                              ESCAN00009200: Positive Response upon command PROGRAM_START not correct
|                              ESCAN00010705: Rework command PROGRAM_RESET
|                              ESCAN00010706: Return the status of event channels
|                              ESCAN00010707: Consistency check in case of no DAQ released
|                              ESCAN00008008: Apply PSC naming convention for types and structures
|                              ESCAN00009173: Consistency check for generator DLL and component
|                              ESCAN00008007: Rename the post-organified filenames to xcpProf.h and xcpProf.c
|                              ESCAN00009172: Atmega only: Compiler error due to pointer conversion from RAM to Flash
|                              ESCAN00007209: Apply naming convention to callback functions
|                              ESCAN00009144: Minor changes
| 2005-02-01  1.04.00   Tri    ESCAN00010989: Update comment for version scan
|                              ESCAN00010848: Move timestamp unit of response to GET_DAQ_EVENT_INFO in low nibble
| 2005-02-17  1.05.00   Tri    ESCAN00011210: Support GENy Fwk 1.3 DLL Versions
| 2005-02-28  1.06.00   Tri    ESCAN00010961: Include XCP Transport Layer on CAN
| 2005-05-10  1.07.00   Tri    ESCAN00011446: Tasking Compiler only: Compiler Warnings
|                              ESCAN00012314: Compatibility with CANape 5.5.x regarding timestamp unit
|                              ESCAN00012356: Support data paging on Star12X / Metrowerks
|                              ESCAN00012617: Add service to retrieve XCP state
| 2006-01-03  1.08.00   Tri    ESCAN00013899: Data acquisition not possible during cold start
|                              ESCAN00009196: PROGRAM_FORMAT is not implemented as specified
|                              ESCAN00009199: Negative Response to command PROGRAM_PREPARE is not correct
|                              ESCAN00009202: Programming Info not implemented correctly
|                              ESCAN00014313: Warning because of undefined 'kXcpStimOdtCount'
|                              ESCAN00013634: Remove kXcpPacketHeaderSize
|                              ESCAN00014710: Rework Calibration Data Page Freeze
|                              ESCAN00014712: Rework Segment Info and Page Info
|                              ESCAN00014775: Delayed EEPROM read access not possible
| 2006-03-09  1.09.00   Tri    ESCAN00013637: Support command TRANSPORT_LAYER_CMD
|                              ESCAN00015283: Start of a single DAQ list is not possible
|                              ESCAN00015607: Support XCP on FlexRay Transport Layer
| 2006-05-05  1.10.00   Tri    ESCAN00016158: Add demo disclaimer to XCP Basic
|                              ESCAN00016098: Calculation of CRC16 CCITT is not correct
| 2006-05-30  1.11.00   Tri    ESCAN00016225: Support Cp_XcpOnLin
| 2006-07-18  1.12.00   Tri    ESCAN00016955: Support AUTOSAR CRC module
|                              ESCAN00016958: Delayed EEPROM read access not possible
| 2006-10-26  1.13.00   Tri    ESCAN00017516: Support Cp_XcpOnCanAsr
|                              ESCAN00017504: Replace P_MEM_ROM by MEMORY_FAR resp. V_MEMRAM2_FAR
|                              ESCAN00017804: Multiple definitions of XCP_DISABLE_TESTMODE
|                              ESCAN00017878: Overwriting of memory during data acquisition allocation
| 2007-01-30  1.14.00   Tri    ESCAN00018808: Support data paging on Star12X / Cosmic
| 2007-04-03  1.15.00   Eta    ESCAN00018153: Overwriting of memory during data stimulation
|                       Svh    ESCAN00020126: Commands SHORT_DOWNLOAD and MODIFY_BITS must be supported
|                              ESCAN00012618: Support command MODIFY_BITS
|                              ESCAN00020127: It has to be possible to en-/disable XCP globally
|                              ESCAN00019094: Extend implementation for runtime deactivation of XCP (professional)
|                              ESCAN00020128: Add AUTOSAR based API
|                              ESCAN00018154: Support overwriting of XcpSendDto() in header
|                              ESCAN00015859: Support memory read protection
| 2007-05-25  1.16.00   Svh    ESCAN00020906: Compiler error due to incorrect pointer assignment
| 2007-07-09  1.16.01   Hr     Support AUTOSAR Memory Mapping
| 2007-12-07  1.16.02   Hr     ISS046 - Only CTOs are flushed by the Protocol Layer
| 2007-09-14  1.17.00   Svh    ESCAN00022293: Support for SET_SEGMENT_MODE and GET_SEGMENT_MODE added
| 2007-12-17  1.18.00   Svh    ESCAN00023759: Compile error for MCS12x
| 2008-03-17  1.19.00   Svh    ESCAN00021035: XcpSendCallBack() always returns 1
|                              ESCAN00024265: STIM with time stamp is not supported
|                              ESCAN00024863: Missing error code in CC_TRANSPORT_LAYER_CMD
|                              ESCAN00025020: Possible stack issues with big MAX_DTO values in case Send Queue is not used
|                              ESCAN00023570: Do not set default answer is last CRM is still pending
| 2008-04-10  1.20.00   Svh    ESCAN00025979: tXcpDto wrong structure ordering causing erroneous one-time Stim trigger
| 2008-04-30  1.21.00   Eta    ESCAN00026424: compiler error when using Cosmic with option -pck
|                       Svh    ESCAN00026491: Data inconsistency of ODTs in case of Overrun + FlexRay
| 2008-04-30  1.21.01   Svh    ESCAN00026541: compiler error due to unknown symbol
| 2008-06-04  1.21.02   Svh    ESCAN00027343: Redefinition of ApplXcpSendFlush
| 2008-07-21  1.22.00   Hr     ESCAN00022545: Memory Read Protection always returns Ok to CANape
|                              ESCAN00020637: Support different Info Time Unit for DTO handling
|                              ESCAN00017954: Support MIN_ST_PGM
|                              ESCAN00017951: Add open interface for command processing
|                              ESCAN00028579: CC_PROGRAM_START should support an application callback
|                       Svh    ESCAN00028720: Support ADDRESS_GRANULARITY WORD
| 2008-09-10  1.23.00   Svh    ESCAN00029890: Incorrect checksum calculation
|                              ESCAN00029896: Command pending for several call backs added
|                              ESCAN00029897: XcpStimEventStatus() returns 1 also if no STIM data is available
|                              ESCAN00029905: Configuration of parameter MIN_ST in response of GET_COMM_MODE_INFO command added
| 2008-10-01  1.23.01   Hr     ESCAN00030382: Compiler error due to missing ;
| 2008-10-10  1.23.02   Bwr    ESCAN00030037: Support for more than 255 ODT entries
| 2008-12-01  1.24.00   Hr     ESCAN00031342: Version information of implementation inconsistent to release version information
|                              ESCAN00031726: Add support for XcpOnTcpIpAsr
|                              ESCAN00031948: Event gets lost, if a Response is still pending
|                              ESCAN00031949: Add error check for ODT_SIZE_WORD with no DAQ_HDR_ODT_DAQ
|                       Bwr    ESCAN00030566: SET_REQUEST with incorrect mode is ignored
|                              ESCAN00030601: Support for more than 255 ODTs
| 2009-02-05  1.24.01   Hr     ESCAN00032861: CC_SET_DAQ_PTR fails due to Diab Data Compiler bug
| 2009-02-27  1.24.02   Hr     ESCAN00031794: Compiler warning: large type was implicitly cast to small type
|                              ESCAN00033655: Canbedded compile error due to uint8
| 2009-05-13  1.25.00   Hr     ESCAN00033909: New features implemented: Prog Write Protection, Timestamps, Calibration activation
| 2009-10-08  1.25.01   Hr     ESCAN00038283: After second measurement start with INCA no timestamps are generated anymore.
|                              ESCAN00039240: Compile error by uint8
|                              ESCAN00039241: Variables not in NOINIT sections
| 2009-11-26            Hr     ESCAN00039350: TMS320 Compile error: struct has no field "EightByteField"
| 2010-03-24  1.26.00   Hr     ESCAN00041784: new API for better calibration support
|                              ESCAN00041784: Queue size calculation incorrect under certain conditions
| 2010-05-25  1.26.01   Hr     ESCAN00042660: Send queue variables to small
|                              ESCAN00043113: Compiler error: identifier uint16 not declared
| 2010-07-08  1.26.02   Hr     ESCAN00043335: Queue size calculation incorrect on 32Bit Platforms
| 2010-10-12  1.26.03   Hr     ESCAN00045791: Send Queue limited to 255 Entries by typecasts
| 2011-02-11  1.27.00   Hr     ESCAN00047153: 'XCP on LIN' and 'XCP on CAN' can not be used in the same configuration.
|                              ESCAN00048613: CC_PROGRAM_CLEAR does not make use of programming write protection
|                              ESCAN00049091: Optimization to prevent a goto in the code
|                              ESCAN00049090: Software might hang in endless software loop
| 2011-06-06  1.27.01   Hr     ESCAN00051222: Customer can't compile XCP when disabling the DAQ feature
| 2011-07-19  1.27.02   Ore    ESCAN00052011: Reading memory of the ECU via XCP is not possible. XCP Connect aborts with error condition PAGE_MODE_NOT_VALID (=0x27)
| 2011-08-29  1.27.03   Hr     ESCAN00052721: Compiler Error because MEMORY_ROM definition
|                              ESCAN00053956: Check DAQ lists for validity before they are started
| 2011-11-25  1.27.04   Hr     ESCAN00054318: Issue of memory read/write protection in DAQ measurement
| 2012-02-20  1.27.05   Hr     ESCAN00055216: DAQ Lists can be extended after START_STOP_SYNCH
| 2012-05-31  1.27.06   Hr     ESCAN00058916: Trap if WRITE_DAQ is used before a DAQ list is created.
| 2012-08-13  1.28.00   Hr     ESCAN00038632: Support for address doubling in CANape for DSP micros
| 2013-06-17  1.28.01   Hr     ESCAN00068052: Provide an API to detect XCP state and usage
| 2013-09-17  1.28.02   Hr     ESCAN00069598: The PROGRAM_MAX command uses a wrong length
|                              ESCAN00067667: Compiler warning: warning #177-D: label "negative_response1" was declared but never referenced
| 2013-12-09  1.29.00   Hr     ESCAN00072412: Provide an API to detect XCP state and usage
|                              ESCAN00072503: Support custom CRC Cbk
|                              ESCAN00072505: Support Generic GET_ID
| 2015-03-26  1.30.00   Hr     ESCAN00082098: Time Check for DAQ lists
| 2016-01-12  1.30.01   Hr     ESCAN00087368: Unexpected byte order used on word-addressed platforms (e.g. TMS320)
| 2016-06-24  1.30.02   Hr     ESCAN00090639: Compiler error: "truncating assignment" 
|                              ESCAN00090685: Max PID not checked against 0x7C if Overload Indication is active
|                              ESCAN00090687: Prescaler does not disable single DAQ list per event optimization
|                              ESCAN00090699: MPU detects illegal access to variable dto
| 2016-11-18  1.30.03   Hr     ESCAN00091645: Wrong memory size calculation during memory allocation
|                              ESCAN00092933: XcpMemCpy does not fully utilize XCP_ENABLE_MEM_ACCESS_BY_APPL
|                              ESCAN00092934: Max PID not checked against 0x7B if Overload Indication is active
| 2017-09-01  1.30.04   Hr     ESCAN00095506: TMS320 wrong Endianess used during memory access.
|                              ESCAN00096039: Compiler error: out of bounds array access optimized away
|                              ESCAN00096161: Compiler warning: Unused variable qs
|                              ESCAN00096627: Improve plausibility check of DAQ allocation
|***************************************************************************/

#if !defined ( __XCP_H_ )
#define __XCP_H_


/***************************************************************************/
/* Include                                                                 */
/***************************************************************************/

/* Includes for XcpProf.c/XcpBasic.c */
  #include "XcpCfg.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Include the Transport Layer for LIN if available. */

/* Include the Transport Layer for FlexRay if available. */

/* PRQA S 0857 EOF */ /* MD_MSR_1.1_857 */
/* PRQA S 0828 EOF */ /* MD_MSR_1.1_828 */
/* PRQA S 3453 EOF */ /* MD_MSR_19.7 */
/* PRQA S 3458 EOF */ /* MD_MSR_19.4 */

/***************************************************************************/
/* Version                                                                 */
/***************************************************************************/

/* BCD coded version number of XCP module */
/* ##V_CFG_MANAGEMENT ##CQProject : Cp_Xcp CQComponent : Implementation */
#define CP_XCP_VERSION         0x0130u
#define CP_XCP_RELEASE_VERSION 0x04u

/* Version of the XCP Protocol Layer Specification V1.0 */
#if ! defined ( XCP_VERSION )
  #define XCP_VERSION 0x0100
#endif

#define XCP_VENDOR_ID   30u
#define XCP_MODULE_ID   26u


/****************************************************************************/
/* Definitions                                                              */
/****************************************************************************/

/* Definition of endianess. */
#if defined ( XCP_CPUTYPE_BIGENDIAN ) || defined ( XCP_CPUTYPE_LITTLEENDIAN )
#else
  #if defined ( C_CPUTYPE_BIGENDIAN )
    #define XCP_CPUTYPE_BIGENDIAN
  #endif
  #if defined ( C_CPUTYPE_LITTLEENDIAN )
    #define XCP_CPUTYPE_LITTLEENDIAN
  #endif
  #if defined ( CPU_BYTE_ORDER )
    #if ( CPU_BYTE_ORDER == HIGH_BYTE_FIRST )
      #define XCP_CPUTYPE_BIGENDIAN
    #endif
    #if ( CPU_BYTE_ORDER == LOW_BYTE_FIRST )
      #define XCP_CPUTYPE_LITTLEENDIAN
    #endif
  #endif
#endif


/***************************************************************************/
/* Commands                                                                */
/***************************************************************************/


/*-------------------------------------------------------------------------*/
/* Standard Commands */

#define CC_CONNECT                        0xFF
#define CC_DISCONNECT                     0xFE
#define CC_GET_STATUS                     0xFD
#define CC_SYNC                           0xFC

#define CC_GET_COMM_MODE_INFO             0xFB
#define CC_GET_ID                         0xFA
#define CC_SET_REQUEST                    0xF9
#define CC_GET_SEED                       0xF8
#define CC_UNLOCK                         0xF7
#define CC_SET_MTA                        0xF6
#define CC_UPLOAD                         0xF5
#define CC_SHORT_UPLOAD                   0xF4
#define CC_BUILD_CHECKSUM                 0xF3
                                          
#define CC_TRANSPORT_LAYER_CMD            0xF2
#define CC_USER_CMD                       0xF1


/*-------------------------------------------------------------------------*/
/* Calibration Commands*/

#define CC_DOWNLOAD                       0xF0

#define CC_DOWNLOAD_NEXT                  0xEF
#define CC_DOWNLOAD_MAX                   0xEE
#define CC_SHORT_DOWNLOAD                 0xED
#define CC_MODIFY_BITS                    0xEC


/*-------------------------------------------------------------------------*/
/* Page switching Commands (PAG) */

#define CC_SET_CAL_PAGE                   0xEB
#define CC_GET_CAL_PAGE                   0xEA

#define CC_GET_PAG_PROCESSOR_INFO         0xE9
#define CC_GET_SEGMENT_INFO               0xE8
#define CC_GET_PAGE_INFO                  0xE7
#define CC_SET_SEGMENT_MODE               0xE6
#define CC_GET_SEGMENT_MODE               0xE5
#define CC_COPY_CAL_PAGE                  0xE4


/*-------------------------------------------------------------------------*/
/* DATA Acquisition and Stimulation Commands (DAQ/STIM) */
                                          
#define CC_CLEAR_DAQ_LIST                 0xE3
#define CC_SET_DAQ_PTR                    0xE2
#define CC_WRITE_DAQ                      0xE1
#define CC_SET_DAQ_LIST_MODE              0xE0
#define CC_GET_DAQ_LIST_MODE              0xDF
#define CC_START_STOP_DAQ_LIST            0xDE
#define CC_START_STOP_SYNCH               0xDD

#define CC_GET_DAQ_CLOCK                  0xDC
#define CC_READ_DAQ                       0xDB
#define CC_GET_DAQ_PROCESSOR_INFO         0xDA
#define CC_GET_DAQ_RESOLUTION_INFO        0xD9 
#define CC_GET_DAQ_LIST_INFO              0xD8
#define CC_GET_DAQ_EVENT_INFO             0xD7

#define CC_FREE_DAQ                       0xD6
#define CC_ALLOC_DAQ                      0xD5
#define CC_ALLOC_ODT                      0xD4
#define CC_ALLOC_ODT_ENTRY                0xD3


/*-------------------------------------------------------------------------*/
/* Non volatile memory Programming Commands PGM */

#define CC_PROGRAM_START                  0xD2
#define CC_PROGRAM_CLEAR                  0xD1
#define CC_PROGRAM                        0xD0
#define CC_PROGRAM_RESET                  0xCF

#define CC_GET_PGM_PROCESSOR_INFO         0xCE
#define CC_GET_SECTOR_INFO                0xCD
#define CC_PROGRAM_PREPARE                0xCC
#define CC_PROGRAM_FORMAT                 0xCB 
#define CC_PROGRAM_NEXT                   0xCA
#define CC_PROGRAM_MAX                    0xC9
#define CC_PROGRAM_VERIFY                 0xC8


/*-------------------------------------------------------------------------*/
/* Customer specific commands */

#define CC_WRITE_DAQ_MULTIPLE             0x81


/*-------------------------------------------------------------------------*/
/* Packet Identifiers Slave -> Master */
#define PID_RES                           0xFF   /* response packet        */
#define PID_ERR                           0xFE   /* error packet           */
#define PID_EV                            0xFD   /* event packet           */
#define PID_SERV                          0xFC   /* service request packet */


/*-------------------------------------------------------------------------*/
/* Command Return Codes */

#define CRC_CMD_SYNCH           0x00

#define CRC_CMD_BUSY            0x10
#define CRC_DAQ_ACTIVE          0x11
#define CRC_PRM_ACTIVE          0x12

#define CRC_CMD_UNKNOWN         0x20
#define CRC_CMD_SYNTAX          0x21
#define CRC_OUT_OF_RANGE        0x22
#define CRC_WRITE_PROTECTED     0x23
#define CRC_ACCESS_DENIED       0x24
#define CRC_ACCESS_LOCKED       0x25
#define CRC_PAGE_NOT_VALID      0x26
#define CRC_PAGE_MODE_NOT_VALID 0x27
#define CRC_SEGMENT_NOT_VALID   0x28
#define CRC_SEQUENCE            0x29
#define CRC_DAQ_CONDIF          0x2A

#define CRC_MEMORY_OVERFLOW     0x30
#define CRC_GENERIC             0x31
#define CRC_VERIFY              0x32


/*-------------------------------------------------------------------------*/
/* Event Codes */

#define EVC_RESUME_MODE        0x00
#define EVC_CLEAR_DAQ          0x01
#define EVC_STORE_DAQ          0x02
#define EVC_STORE_CAL          0x03
#define EVC_CMD_PENDING        0x05
#define EVC_DAQ_OVERLOAD       0x06
#define EVC_SESSION_TERMINATED 0x07
#define EVC_USER               0xFE
#define EVC_TRANSPORT          0xFF


/*-------------------------------------------------------------------------*/
/* Service Request Codes */ 

#define SERV_RESET 0x00 /* Slave requesting to be reset */
#define SERV_TEXT  0x01 /* Plain ASCII text null terminated */



/***************************************************************************/
/* Definitions                                                             */
/***************************************************************************/

/*-------------------------------------------------------------------------*/
/* ResourceMask (CONNECT) */

#define RM_CAL_PAG                  0x01
#define RM_DAQ                      0x04
#define RM_STIM                     0x08
#define RM_PGM                      0x10


/*-------------------------------------------------------------------------*/
/* CommModeBasic (CONNECT) */

#define PI_MOTOROLA                   0x01

#define CMB_BYTE_ORDER                (0x01u<<0)
#define CMB_ADDRESS_GRANULARITY       (0x03u<<1)
#define CMB_SLAVE_BLOCK_MODE          (0x01u<<6)
#define CMB_OPTIONAL                  (0x01u<<7)

#define CMB_ADDRESS_GRANULARITY_BYTE  (0<<1)
#define CMB_ADDRESS_GRANULARITY_WORD  (1<<1)
#define CMB_ADDRESS_GRANULARITY_DWORD (2<<1)
#define CMB_ADDRESS_GRANULARITY_QWORD (3<<1)


/*-------------------------------------------------------------------------*/
/* Protocol Info (GET_COMM_MODE_INFO - COMM_OPTIONAL) */

#define CMO_MASTER_BLOCK_MODE  0x01
#define CMO_INTERLEAVED_MODE   0x02   


/*-------------------------------------------------------------------------*/
/* Session Status (GET_STATUS and SET_REQUEST) */

#define SS_STORE_CAL_REQ       0x0001u 
#define SS_BLOCK_UPLOAD        0x0002u /* Internal */
#define SS_STORE_DAQ_REQ       0x0004u
#define SS_CLEAR_DAQ_REQ       0x0008u
#define SS_ERROR               0x0010u /* Internal */
#define SS_CONNECTED           0x0020u /* Internal */
#define SS_DAQ                 0x0040u
#define SS_RESUME              0x0080u
#define SS_POLLING             0x0100u /* Internal */


/*-------------------------------------------------------------------------*/
/* Identifier Type (GET_ID) */

#define IDT_ASCII              0
#define IDT_ASAM_NAME          1
#define IDT_ASAM_PATH          2
#define IDT_ASAM_URL           3
#define IDT_ASAM_UPLOAD        4
#define IDT_VECTOR_MAPNAMES    0xDB

/*-------------------------------------------------------------------------*/
/* Checksum Types (BUILD_CHECKSUM) */

#define XCP_CHECKSUM_TYPE_ADD11      0x01  /* Add BYTE into a BYTE checksum, ignore overflows */
#define XCP_CHECKSUM_TYPE_ADD12      0x02  /* Add BYTE into a WORD checksum, ignore overflows */
#define XCP_CHECKSUM_TYPE_ADD14      0x03  /* Add BYTE into a DWORD checksum, ignore overflows */
#define XCP_CHECKSUM_TYPE_ADD22      0x04  /* Add WORD into a WORD checksum, ignore overflows, blocksize must be modulo 2 */
#define XCP_CHECKSUM_TYPE_ADD24      0x05  /* Add WORD into a DWORD checksum, ignore overflows, blocksize must be modulo 2 */ 
#define XCP_CHECKSUM_TYPE_ADD44      0x06  /* Add DWORD into DWORD, ignore overflows, blocksize must be modulo 4 */
#define XCP_CHECKSUM_TYPE_CRC16      0x07  /* See CRC error detection algorithms */
#define XCP_CHECKSUM_TYPE_CRC16CCITT 0x08  /* See CRC error detection algorithms */
#define XCP_CHECKSUM_TYPE_CRC32      0x09  /* See CRC error detection algorithms */
#define XCP_CHECKSUM_TYPE_DLL        0xFF  /* User defined, ASAM MCD 2MC DLL Interface */


/*-------------------------------------------------------------------------*/
/* Page Mode (SET_CAL_PAGE) */

#define CAL_ECU                0x01
#define CAL_XCP                0x02
#define CAL_ALL                0x80        /* not supported */


/*-------------------------------------------------------------------------*/
/* PAG_PROPERTIES (GET_PAG_PROCESSOR_INFO) */

#define PAG_PROPERTY_FREEZE               0x01


/*-------------------------------------------------------------------------*/
/* PAGE_PROPERTIES (GET_PAGE_INFO)*/

#define ECU_ACCESS_TYPE                   0x03
#define XCP_READ_ACCESS_TYPE              0x0C
#define XCP_WRITE_ACCESS_TYPE             0x30

/* ECU_ACCESS_TYPE */
#define ECU_ACCESS_NONE                   (0<<0)
#define ECU_ACCESS_WITHOUT                (1<<0)
#define ECU_ACCESS_WITH                   (2<<0)
#define ECU_ACCESS_DONT_CARE              (3<<0)

/* XCP_READ_ACCESS_TYPE */
#define XCP_READ_ACCESS_NONE              (0<<2)
#define XCP_READ_ACCESS_WITHOUT           (1<<2)
#define XCP_READ_ACCESS_WITH              (2<<2)
#define XCP_READ_ACCESS_DONT_CARE         (3<<2)

/* XCP_WRITE_ACCESS_TYPE */
#define XCP_WRITE_ACCESS_NONE             (0<<4)
#define XCP_WRITE_ACCESS_WITHOUT          (1<<4)
#define XCP_WRITE_ACCESS_WITH             (2<<4)
#define XCP_WRITE_ACCESS_DONT_CARE        (3<<4)


/*-------------------------------------------------------------------------*/
/* SEGMENT_MODE (GET_SEGMENT_MODE, SET_SEGMENT_MODE) */

#define SEGMENT_FLAG_FREEZE               0x01 /* */


/*-------------------------------------------------------------------------*/
/* DAQ_LIST_MODE (GET_DAQ_LIST_MODE, SET_DAQ_LIST_MODE) */

#define DAQ_FLAG_SELECTED                 0x01u /* */
#define DAQ_FLAG_DIRECTION                0x02u /* Data Stimulation Mode */

#define DAQ_FLAG_TIMESTAMP                0x10u /* Timestamps */
#define DAQ_FLAG_NO_PID                   0x20u /* No PID */
#define DAQ_FLAG_RUNNING                  0x40u /* Is started */
#define DAQ_FLAG_RESUME                   0x80u /* Resume Mode */

#define DAQ_FLAG_RESERVED                 0x08u 
#define DAQ_FLAG_OVERRUN                  0x08u /* Overun (Internal Use) */


/*-------------------------------------------------------------------------*/
/* GET_DAQ_PROCESSOR_INFO */

/* DAQ_PROPERTIES */
#define DAQ_PROPERTY_CONFIG_TYPE          0x01
#define DAQ_PROPERTY_PRESCALER            0x02
#define DAQ_PROPERTY_RESUME               0x04
#define DAQ_PROPERTY_BIT_STIM             0x08
#define DAQ_PROPERTY_TIMESTAMP            0x10
#define DAQ_PROPERTY_NO_PID               0x20
#define DAQ_PROPERTY_OVERLOAD_INDICATION  0xC0

/* DAQ Overload Indication Type */
#define DAQ_OVERLOAD_INDICATION_NONE      (0<<6)
#define DAQ_OVERLOAD_INDICATION_PID       (1<<6)
#define DAQ_OVERLOAD_INDICATION_EVENT     (2<<6)

/* DAQ_KEY_BYTE */
#define DAQ_OPT_TYPE                      0x0F
#define DAQ_EXT_TYPE                      0x30
#define DAQ_HDR_TYPE                      0xC0

/* DAQ Optimisation Type */
#define DAQ_OPT_DEFAULT                   (0<<0)
#define DAQ_OPT_ODT_16                    (1<<0)
#define DAQ_OPT_ODT_32                    (2<<0)
#define DAQ_OPT_ODT_64                    (3<<0)
#define DAQ_OPT_ALIGNMENT                 (4<<0)
#define DAQ_OPT_MAX_ENTRY_SIZE            (5<<0)

/* DAQ Address Extension Scope */
#define DAQ_EXT_FREE                      (0<<4)
#define DAQ_EXT_ODT                       (1<<4)
#define DAQ_EXT_DAQ                       (3<<4)

/* DAQ Identification Field Type */
#define DAQ_HDR_PID                       (0<<6)
#define DAQ_HDR_ODT_DAQB                  (1<<6)
#define DAQ_HDR_ODT_DAQW                  (2<<6)
#define DAQ_HDR_ODT_FIL_DAQW              (3<<6)
 

/*-------------------------------------------------------------------------*/
/* GET_DAQ_RESOLUTION_INFO */

/* TIMESTAMP_MODE */
#define DAQ_TIMESTAMP_SIZE  0x07
#define DAQ_TIMESTAMP_FIXED 0x08
#define DAQ_TIMESTAMP_UNIT  0xF0

/* DAQ Timestamp Size */
#define DAQ_TIMESTAMP_OFF         (0<<0)
#define DAQ_TIMESTAMP_BYTE        (1<<0)
#define DAQ_TIMESTAMP_WORD        (2<<0)
#define DAQ_TIMESTAMP_DWORD       (4<<0)

/* DAQ Timestamp Unit */
#define DAQ_TIMESTAMP_UNIT_1NS    (0<<4)
#define DAQ_TIMESTAMP_UNIT_10NS   (1<<4)
#define DAQ_TIMESTAMP_UNIT_100NS  (2<<4)
#define DAQ_TIMESTAMP_UNIT_1US    (3<<4)
#define DAQ_TIMESTAMP_UNIT_10US   (4<<4)  
#define DAQ_TIMESTAMP_UNIT_100US  (5<<4)
#define DAQ_TIMESTAMP_UNIT_1MS    (6<<4)
#define DAQ_TIMESTAMP_UNIT_10MS   (7<<4)
#define DAQ_TIMESTAMP_UNIT_100MS  (8<<4)
#define DAQ_TIMESTAMP_UNIT_1S     (9<<4)


/*-------------------------------------------------------------------------*/
/* DAQ_LIST_PROPERTIES (GET_DAQ_LIST_INFO) */

#define DAQ_LIST_PREDEFINED           0x01
#define DAQ_LIST_FIXED_EVENT          0x02
#define DAQ_LIST_DIR_DAQ              0x04
#define DAQ_LIST_DIR_STIM             0x08


/*-------------------------------------------------------------------------*/
/* EVENT_PROPERTY (GET_DAQ_EVENT_INFO) */

#define DAQ_EVENT_DIRECTION_DAQ      0x04
#define DAQ_EVENT_DIRECTION_STIM     0x08
#define DAQ_EVENT_DIRECTION_DAQ_STIM 0x0C


/*-------------------------------------------------------------------------*/
/* Comm mode programming parameter (PROGRAM_START) */

#define PI_PGM_BLOCK_DOWNLOAD      0x01
#define PI_PGM_BLOCK_UPLOAD        0x40   


/*-------------------------------------------------------------------------*/
/* PGM_PROPERTIES (GET_PGM_PROCESSOR_INFO) */

#define PGM_ACCESS_TYPE                   0x03
#define PGM_COMPRESSION_TYPE              0x0C
#define PGM_ENCRYPTION_TYPE               0x30
#define PGM_NON_SEQ_TYPE                  0xC0

/* PGM Access Mode */
#define PGM_ACCESS_ABSOLUTE               (1<<0)
#define PGM_ACCESS_FUNCTIONAL             (2<<0)
#define PGM_ACCESS_FREE                   (3<<0)

/* PGM Compression type */
#define PGM_COMPRESSION_NONE              (0<<2)
#define PGM_COMPRESSION_SUPPORTED         (1<<2)
#define PGM_COMPRESSION_REQUIRED          (3<<2)

/* PGM Encryption type */
#define PGM_ENCRYPTION_NONE               (0<<4)
#define PGM_ENCRYPTION_SUPPORTED          (1<<4)
#define PGM_ENCRYPTION_REQUIRED           (3<<4)

/* PGM non sequential programming type */
#define PGM_NON_SEQ_NONE                  (0<<6)
#define PGM_NON_SEQ_SUPPORTED             (1<<6)
#define PGM_NON_SEQ_REQUIRED              (3<<6)

/* Compatibility defines */

#if defined ( XCP_TRANSPORT_LAYER_TYPE_CAN )
  #define kXcpMaxCTO kCanXcpMaxCTO
  #define kXcpMaxDTO kCanXcpMaxDTO
#endif


/***************************************************************************/
/* XCP Commands and Responces, Type Definition */
/***************************************************************************/

/* Protocol command structure definition */
#define CRO_CMD                                         CRO_BYTE(0)
#define CRM_CMD                                         CRM_BYTE(0)
#define CRM_ERR                                         CRM_BYTE(1)
/* CONNECT */

#define CRO_CONNECT_LEN                                 2
#define CRO_CONNECT_MODE                                CRO_BYTE(1)
#define CRM_CONNECT_LEN                                 8
#define CRM_CONNECT_RESOURCE                            CRM_BYTE(1)
#define CRM_CONNECT_COMM_BASIC                          CRM_BYTE(2)
#define CRM_CONNECT_MAX_CTO_SIZE                        CRM_BYTE(3)
#define CRM_CONNECT_MAX_DTO_SIZE                        CRM_WORD(2)
#define CRM_CONNECT_MAX_DTO_SIZE_WRITE(size)            CRM_WORD_WRITE(2, size)
#define CRM_CONNECT_PROTOCOL_VERSION                    CRM_BYTE(6)
#define CRM_CONNECT_TRANSPORT_VERSION                   CRM_BYTE(7)


/* DISCONNECT */
                                        
#define CRO_DISCONNECT_LEN                              1
#define CRM_DISCONNECT_LEN                              1


/* GET_STATUS */                                        

#define CRO_GET_STATUS_LEN                              1

#define CRM_GET_STATUS_LEN                              6
#define CRM_GET_STATUS_STATUS                           CRM_BYTE(1)
#define CRM_GET_STATUS_PROTECTION                       CRM_BYTE(2)
#define CRM_GET_STATUS_CONFIG_ID                        CRM_WORD(2)
#define CRM_GET_STATUS_CONFIG_ID_WRITE(id)              CRM_WORD_WRITE(2, id)


/* SYNCH */
                                        
#define CRO_SYNCH_LEN                                   1

#define CRM_SYNCH_LEN                                   2
#define CRM_SYNCH_RESULT                                CRM_BYTE(1)
                                                 
                                                       
/* GET_COMM_MODE_INFO */

#define CRO_GET_COMM_MODE_INFO_LEN                      1

#define CRM_GET_COMM_MODE_INFO_LEN                      8
#define CRM_GET_COMM_MODE_INFO_COMM_OPTIONAL            CRM_BYTE(2)
#define CRM_GET_COMM_MODE_INFO_MAX_BS                   CRM_BYTE(4)
#define CRM_GET_COMM_MODE_INFO_MIN_ST                   CRM_BYTE(5)
#define CRM_GET_COMM_MODE_INFO_QUEUE_SIZE               CRM_BYTE(6)
#define CRM_GET_COMM_MODE_INFO_DRIVER_VERSION           CRM_BYTE(7)


/* GET_ID */
                                            
#define CRO_GET_ID_LEN                                  2
#define CRO_GET_ID_TYPE                                 CRO_BYTE(1)

#define CRM_GET_ID_LEN                                  8
#define CRM_GET_ID_MODE                                 CRM_BYTE(1)
#define CRM_GET_ID_LENGTH                               CRM_DWORD(1)
#define CRM_GET_ID_LENGTH_WRITE(len)                    CRM_DWORD_WRITE(1, len)
#define CRM_GET_ID_DATA                                 (&CRM_BYTE(8))

/* SET_REQUEST */

#define CRO_SET_REQUEST_LEN                             4
#define CRO_SET_REQUEST_MODE                            CRO_BYTE(1)
#define CRO_SET_REQUEST_CONFIG_ID                       CRO_WORD(1)

#define CRM_SET_REQUEST_LEN                             1

                                                        
/* GET_SEED */
                                          
#define CRO_GET_SEED_LEN                                3
#define CRO_GET_SEED_MODE                               CRO_BYTE(1)
#define CRO_GET_SEED_RESOURCE                           CRO_BYTE(2)

#define CRM_GET_SEED_LEN                                (CRM_GET_SEED_LENGTH+2u)
#define CRM_GET_SEED_LENGTH                             CRM_BYTE(1)
#define CRM_GET_SEED_DATA                               (&CRM_BYTE(2))

                                                        
/* UNLOCK */
                                            
#define CRO_UNLOCK_LEN                                  8
#define CRO_UNLOCK_LENGTH                               CRO_BYTE(1)
#define CRO_UNLOCK_KEY                                  (&CRO_BYTE(2))

#define CRM_UNLOCK_LEN                                  2
#define CRM_UNLOCK_PROTECTION                           CRM_BYTE(1)

                                                        
/* SET_MTA */

#define CRO_SET_MTA_LEN                                 8
#define CRO_SET_MTA_EXT                                 CRO_BYTE(3)
#define CRO_SET_MTA_ADDR                                CRO_DWORD(1)

#define CRM_SET_MTA_LEN                                 1


/* UPLOAD */
                                            
#define CRM_UPLOAD_MAX_SIZE                             ((vuint8)(kXcpMaxCTO-1))
#define CRO_UPLOAD_LEN                                  2
#define CRO_UPLOAD_SIZE                                 CRO_BYTE(1)

#define CRM_UPLOAD_LEN                                  1 /* +CRO_UPLOAD_SIZE */
#define CRM_UPLOAD_DATA                                 (&CRM_BYTE(1))


/* SHORT_UPLOAD */

#define CRO_SHORT_UPLOAD_LEN                            8
#define CRO_SHORT_UPLOAD_SIZE                           CRO_BYTE(1)
#define CRO_SHORT_UPLOAD_EXT                            CRO_BYTE(3)
#define CRO_SHORT_UPLOAD_ADDR                           CRO_DWORD(1)

#define CRM_SHORT_UPLOAD_MAX_SIZE                       ((vuint8)(kXcpMaxCTO-1))

#define CRM_SHORT_UPLOAD_LEN                            1 /* +CRO_SHORT_UPLOAD_SIZE */
#define CRM_SHORT_UPLOAD_DATA                           (&CRM_BYTE(1))


/* BUILD_CHECKSUM */

#define CRO_BUILD_CHECKSUM_LEN                          8
#define CRO_BUILD_CHECKSUM_SIZE                         CRO_DWORD(1)

#define CRM_BUILD_CHECKSUM_LEN                          8
#define CRM_BUILD_CHECKSUM_TYPE                         CRM_BYTE(1)
#define CRM_BUILD_CHECKSUM_RESULT                       CRM_DWORD(1)
#define CRM_BUILD_CHECKSUM_RESULT_WRITE(result)         CRM_DWORD_WRITE(1, result)

       
/* DOWNLOAD */
                                            
#define CRO_DOWNLOAD_MAX_SIZE                           ((vuint8)(kXcpMaxCTO-2))

#define CRO_DOWNLOAD_LEN                                2 /* + CRO_DOWNLOAD_SIZE */
#define CRO_DOWNLOAD_SIZE                               CRO_BYTE(1)
#define CRO_DOWNLOAD_DATA                               (&CRO_BYTE(2))

#define CRM_DOWNLOAD_LEN                                1


/* DOWNLOAD_NEXT */
                                            
#define CRO_DOWNLOAD_NEXT_MAX_SIZE                      ((vuint8)(kXcpMaxCTO-2))

#define CRO_DOWNLOAD_NEXT_LEN                           2 /* + size */
#define CRO_DOWNLOAD_NEXT_SIZE                          CRO_BYTE(1)
#define CRO_DOWNLOAD_NEXT_DATA                          (&CRO_BYTE(2))

#define CRM_DOWNLOAD_NEXT_LEN                           1

                                                        
/* DOWNLOAD_MAX */

#define CRO_DOWNLOAD_MAX_MAX_SIZE                       ((vuint8)(kXcpMaxCTO-1))
#define CRO_DOWNLOAD_MAX_DATA                           (&CRO_BYTE(1))

#define CRM_DOWNLOAD_MAX_LEN                            1


/* SHORT_DOWNLOAD */

#define CRO_SHORT_DOWNLOAD_LEN                          8
#define CRO_SHORT_DOWNLOAD_SIZE                         CRO_BYTE(1)
#define CRO_SHORT_DOWNLOAD_EXT                          CRO_BYTE(3)
#define CRO_SHORT_DOWNLOAD_ADDR                         CRO_DWORD(1)
#define CRO_SHORT_DOWNLOAD_DATA                         (&CRO_BYTE(8))

#define CRM_SHORT_DOWNLOAD_MAX_SIZE                     ((vuint8)(kXcpMaxCTO-8))
#define CRM_SHORT_DOWNLOAD_LEN                          1 /* +CRO_SHORT_UPLOAD_SIZE */

                                                        
/* MODIFY_BITS */

#define CRO_MODIFY_BITS_LEN                             6
#define CRO_MODIFY_BITS_SHIFT                           CRO_BYTE(1)
#define CRO_MODIFY_BITS_AND                             CRO_WORD(1)
#define CRO_MODIFY_BITS_XOR                             CRO_WORD(2)

#define CRM_MODIFY_BITS_LEN                             1

                                                        
/* SET_CAL_PAGE */
                                      
#define CRO_SET_CAL_PAGE_LEN                            4
#define CRO_SET_CAL_PAGE_MODE                           CRO_BYTE(1)
#define CRO_SET_CAL_PAGE_SEGMENT                        CRO_BYTE(2)
#define CRO_SET_CAL_PAGE_PAGE                           CRO_BYTE(3)

#define CRM_SET_CAL_PAGE_LEN                            1

                                                        
/* GET_CAL_PAGE */
                                      
#define CRO_GET_CAL_PAGE_LEN                            3
#define CRO_GET_CAL_PAGE_MODE                           CRO_BYTE(1)
#define CRO_GET_CAL_PAGE_SEGMENT                        CRO_BYTE(2)

#define CRM_GET_CAL_PAGE_LEN                            4
#define CRM_GET_CAL_PAGE_PAGE                           CRM_BYTE(3)


/* GET_PAG_PROCESSOR_INFO */

#define CRO_GET_PAG_PROCESSOR_INFO_LEN                  1

#define CRM_GET_PAG_PROCESSOR_INFO_LEN                  3
#define CRM_GET_PAG_PROCESSOR_INFO_MAX_SEGMENT          CRM_BYTE(1)
#define CRM_GET_PAG_PROCESSOR_INFO_PROPERTIES           CRM_BYTE(2)


/* GET_SEGMENT_INFO */

#define CRO_GET_SEGMENT_INFO_LEN                        5
#define CRO_GET_SEGMENT_INFO_MODE                       CRO_BYTE(1)
#define CRO_GET_SEGMENT_INFO_NUMBER                     CRO_BYTE(2)
#define CRO_GET_SEGMENT_INFO_MAPPING_INDEX              CRO_BYTE(3)
#define CRO_GET_SEGMENT_INFO_MAPPING                    CRO_BYTE(4)

#define CRM_GET_SEGMENT_INFO_LEN                        8
#define CRM_GET_SEGMENT_INFO_MAX_PAGES                  CRM_BYTE(1)
#define CRM_GET_SEGMENT_INFO_ADDRESS_EXTENSION          CRM_BYTE(2)
#define CRM_GET_SEGMENT_INFO_MAX_MAPPING                CRM_BYTE(3)
#define CRM_GET_SEGMENT_INFO_COMPRESSION                CRM_BYTE(4)
#define CRM_GET_SEGMENT_INFO_ENCRYPTION                 CRM_BYTE(5)
#define CRM_GET_SEGMENT_INFO_MAPPING_INFO               CRM_DWORD(1)


/* GET_PAGE_INFO */

#define CRO_GET_PAGE_INFO_LEN                           4
#define CRO_GET_PAGE_INFO_SEGMENT_NUMBER                CRO_BYTE(2)
#define CRO_GET_PAGE_INFO_PAGE_NUMBER                   CRO_BYTE(3)

#define CRM_GET_PAGE_INFO_LEN                           3
#define CRM_GET_PAGE_INFO_PROPERTIES                    CRM_BYTE(1)
#define CRM_GET_PAGE_INFO_INIT_SEGMENT                  CRM_BYTE(2)


/* SET_SEGMENT_MODE */

#define CRO_SET_SEGMENT_MODE_LEN                        3
#define CRO_SET_SEGMENT_MODE_MODE                       CRO_BYTE(1)
#define CRO_SET_SEGMENT_MODE_SEGMENT                    CRO_BYTE(2)

#define CRM_SET_SEGMENT_MODE_LEN                        1


/* GET_SEGMENT_MODE */

#define CRO_GET_SEGMENT_MODE_LEN                        3
#define CRO_GET_SEGMENT_MODE_SEGMENT                    CRO_BYTE(2)

#define CRM_GET_SEGMENT_MODE_LEN                        3
#define CRM_GET_SEGMENT_MODE_MODE                       CRM_BYTE(2)


/* COPY_CAL_PAGE */

#define CRO_COPY_CAL_PAGE_LEN                           5
#define CRO_COPY_CAL_PAGE_SRC_SEGMENT                   CRO_BYTE(1)
#define CRO_COPY_CAL_PAGE_SRC_PAGE                      CRO_BYTE(2)
#define CRO_COPY_CAL_PAGE_DEST_SEGMENT                  CRO_BYTE(3)
#define CRO_COPY_CAL_PAGE_DEST_PAGE                     CRO_BYTE(4)

#define CRM_COPY_CAL_PAGE_LEN                           1


/* CLEAR_DAQ_LIST */

#define CRO_CLEAR_DAQ_LIST_LEN                          4
#define CRO_CLEAR_DAQ_LIST_DAQ                          CRO_WORD(1)

#define CRM_CLEAR_DAQ_LIST_LEN                          1

                                                        
/* SET_DAQ_PTR */

#define CRO_SET_DAQ_PTR_LEN                             6
#define CRO_SET_DAQ_PTR_DAQ                             CRO_WORD(1)
#define CRO_SET_DAQ_PTR_ODT                             CRO_BYTE(4)
#define CRO_SET_DAQ_PTR_IDX                             CRO_BYTE(5)

#define CRM_SET_DAQ_PTR_LEN                             1


/* WRITE_DAQ */

#define CRO_WRITE_DAQ_LEN                               8
#define CRO_WRITE_DAQ_BITOFFSET                         CRO_BYTE(1)
#define CRO_WRITE_DAQ_SIZE                              CRO_BYTE(2)
#define CRO_WRITE_DAQ_EXT                               CRO_BYTE(3)
#define CRO_WRITE_DAQ_ADDR                              CRO_DWORD(1)

#define CRM_WRITE_DAQ_LEN                               1


/* WRITE_DAQ_MULTIPLE */
#define CRO_WRITE_DAQ_MULTIPLE_LEN                      8
#define CRO_WRITE_DAQ_MULTIPLE_COMMAND                  CRO_BYTE(1)
#define CRO_WRITE_DAQ_MULTIPLE_NODAQ                    CRO_BYTE(2)
#define CRO_WRITE_DAQ_MULTIPLE_BITOFFSET(i)             CRO_BYTE(8 + (8*(i)))
#define CRO_WRITE_DAQ_MULTIPLE_SIZE(i)                  CRO_BYTE(9 + (8*(i)))
#define CRO_WRITE_DAQ_MULTIPLE_EXT(i)                   CRO_BYTE(10 + (8*(i)))
#define CRO_WRITE_DAQ_MULTIPLE_ADDR(i)                  CRO_DWORD(1 + (2*(i)))

#define CRM_WRITE_DAQ_MULTIPLE_LEN                      1


/* SET_DAQ_LIST_MODE */

#define CRO_SET_DAQ_LIST_MODE_LEN                       8
#define CRO_SET_DAQ_LIST_MODE_MODE                      CRO_BYTE(1)
#define CRO_SET_DAQ_LIST_MODE_DAQ                       CRO_WORD(1)
#define CRO_SET_DAQ_LIST_MODE_EVENTCHANNEL              CRO_WORD(2)
#define CRO_SET_DAQ_LIST_MODE_PRESCALER                 CRO_BYTE(6)
#define CRO_SET_DAQ_LIST_MODE_PRIORITY                  CRO_BYTE(7)

#define CRM_SET_DAQ_LIST_MODE_LEN                       6


/* GET_DAQ_LIST_MODE */

#define CRO_GET_DAQ_LIST_MODE_LEN                       4
#define CRO_GET_DAQ_LIST_MODE_DAQ                       CRO_WORD(1)

#define CRM_GET_DAQ_LIST_MODE_LEN                       8
#define CRM_GET_DAQ_LIST_MODE_MODE                      CRM_BYTE(1)
#define CRM_GET_DAQ_LIST_MODE_EVENTCHANNEL              CRM_WORD(2)
#define CRM_GET_DAQ_LIST_MODE_EVENTCHANNEL_WRITE(ch)    CRM_WORD_WRITE(2, ch)
#define CRM_GET_DAQ_LIST_MODE_PRESCALER                 CRM_BYTE(6)
#define CRM_GET_DAQ_LIST_MODE_PRIORITY                  CRM_BYTE(7)


/* START_STOP_DAQ_LIST */
                                        
#define CRO_START_STOP_LEN                              4
#define CRO_START_STOP_MODE                             CRO_BYTE(1)
#define CRO_START_STOP_DAQ                              CRO_WORD(1)

#define CRM_START_STOP_LEN                              2
#define CRM_START_STOP_FIRST_PID                        CRM_BYTE(1)


/* START_STOP_SYNCH */
  
#define CRO_START_STOP_SYNC_LEN                         2
#define CRO_START_STOP_SYNC_MODE                        CRO_BYTE(1)

#define CRM_START_STOP_SYNC_LEN                         1


/* GET_DAQ_CLOCK */

#define CRO_GET_DAQ_CLOCK_LEN                           1

#define CRM_GET_DAQ_CLOCK_LEN                           8
#define CRM_GET_DAQ_CLOCK_TIME                          CRM_DWORD(1)
#define CRM_GET_DAQ_CLOCK_TIME_WRITE(time)              CRM_DWORD_WRITE(1, time)


/* READ_DAQ */

#define CRO_READ_DAQ_LEN                                1

#define CRM_READ_DAQ_LEN                                8
#define CRM_READ_DAQ_BITOFFSET                          CRM_BYTE(1)
#define CRM_READ_DAQ_SIZE                               CRM_BYTE(2)
#define CRM_READ_DAQ_EXT                                CRM_BYTE(3)
#define CRM_READ_DAQ_ADDR                               CRM_DWORD(1)


/* GET_DAQ_PROCESSOR_INFO */

#define CRO_GET_DAQ_PROCESSOR_INFO_LEN                  1

#define CRM_GET_DAQ_PROCESSOR_INFO_LEN                  8
#define CRM_GET_DAQ_PROCESSOR_INFO_PROPERTIES           CRM_BYTE(1)
#define CRM_GET_DAQ_PROCESSOR_INFO_MAX_DAQ              CRM_WORD(1)
#define CRM_GET_DAQ_PROCESSOR_INFO_MAX_DAQ_WRITE(ndaq)  CRM_WORD_WRITE(1, ndaq)
#define CRM_GET_DAQ_PROCESSOR_INFO_MAX_EVENT            CRM_WORD(2)
#define CRM_GET_DAQ_PROCESSOR_INFO_MAX_EVENT_WRITE(evt) CRM_WORD_WRITE(2, evt)
#define CRM_GET_DAQ_PROCESSOR_INFO_MIN_DAQ              CRM_BYTE(6)
#define CRM_GET_DAQ_PROCESSOR_INFO_DAQ_KEY_BYTE         CRM_BYTE(7)


/* GET_DAQ_RESOLUTION_INFO */
                                
#define CRO_GET_DAQ_RESOLUTION_INFO_LEN                 1

#define CRM_GET_DAQ_RESOLUTION_INFO_LEN                 8
#define CRM_GET_DAQ_RESOLUTION_INFO_GRANULARITY_DAQ     CRM_BYTE(1)
#define CRM_GET_DAQ_RESOLUTION_INFO_MAX_SIZE_DAQ        CRM_BYTE(2)
#define CRM_GET_DAQ_RESOLUTION_INFO_GRANULARITY_STIM    CRM_BYTE(3)
#define CRM_GET_DAQ_RESOLUTION_INFO_MAX_SIZE_STIM       CRM_BYTE(4)
#define CRM_GET_DAQ_RESOLUTION_INFO_TIMESTAMP_MODE      CRM_BYTE(5)
#define CRM_GET_DAQ_RESOLUTION_INFO_TIMESTAMP_TICKS     CRM_WORD(3)
#define CRM_GET_DAQ_RESOLUTION_INFO_TIMESTAMP_TICKS_WRITE(ticks) CRM_WORD_WRITE(3, ticks)

                                                        
/* GET_DAQ_LIST_INFO */

#define CRO_GET_DAQ_LIST_INFO_LEN                       4
#define CRO_GET_DAQ_LIST_INFO_DAQ                       CRO_WORD(1)

#define CRM_GET_DAQ_LIST_INFO_LEN                       6
#define CRM_GET_DAQ_LIST_INFO_PROPERTIES                CRM_BYTE(1)
#define CRM_GET_DAQ_LIST_INFO_MAX_ODT                   CRM_BYTE(2)
#define CRM_GET_DAQ_LIST_INFO_MAX_ODT_ENTRY             CRM_BYTE(3)
#define CRM_GET_DAQ_LIST_INFO_FIXED_EVENT               CRM_WORD(2)


/* GET_DAQ_EVENT_INFO */

#define CRO_GET_DAQ_EVENT_INFO_LEN                      4
#define CRO_GET_DAQ_EVENT_INFO_EVENT                    CRO_WORD(1)

#define CRM_GET_DAQ_EVENT_INFO_LEN                      7
#define CRM_GET_DAQ_EVENT_INFO_PROPERTIES               CRM_BYTE(1)
#define CRM_GET_DAQ_EVENT_INFO_MAX_DAQ_LIST             CRM_BYTE(2)
#define CRM_GET_DAQ_EVENT_INFO_NAME_LENGTH              CRM_BYTE(3)
#define CRM_GET_DAQ_EVENT_INFO_TIME_CYCLE               CRM_BYTE(4)
#define CRM_GET_DAQ_EVENT_INFO_TIME_UNIT                CRM_BYTE(5)
#define CRM_GET_DAQ_EVENT_INFO_PRIORITY                 CRM_BYTE(6)


/* FREE_DAQ */

#define CRO_FREE_DAQ_LEN                                1

#define CRM_FREE_DAQ_LEN                                1


/* ALLOC_DAQ */

#define CRO_ALLOC_DAQ_LEN                               4
#define CRO_ALLOC_DAQ_COUNT                             CRO_WORD(1)

#define CRM_ALLOC_DAQ_LEN                               1


/* ALLOC_ODT */

#define _CRO_ALLOC_ODT_LEN                              3
#define _CRO_ALLOC_ODT_DAQ                              CRO_WORD(1)
#define _CRO_ALLOC_ODT_COUNT                            CRO_BYTE(1)

#define CRO_ALLOC_ODT_LEN                               5
#define CRO_ALLOC_ODT_DAQ                               CRO_WORD(1)
#define CRO_ALLOC_ODT_COUNT                             CRO_BYTE(4)

#define CRM_ALLOC_ODT_LEN                               1


/* ALLOC_ODT_ENTRY */

#define CRO_ALLOC_ODT_ENTRY_LEN                         6
#define CRO_ALLOC_ODT_ENTRY_DAQ                         CRO_WORD(1)
#define CRO_ALLOC_ODT_ENTRY_ODT                         CRO_BYTE(4)
#define CRO_ALLOC_ODT_ENTRY_COUNT                       CRO_BYTE(5)

#define CRM_ALLOC_ODT_ENTRY_LEN                         1


/* PROGRAM_START */
                                     
#define CRO_PROGRAM_START_LEN                           1

#define CRM_PROGRAM_START_LEN                           7
#define CRM_PROGRAM_COMM_MODE_PGM                       CRM_BYTE(2) 
#define CRM_PROGRAM_MAX_CTO_PGM                         CRM_BYTE(3) 
#define CRM_PROGRAM_MAX_BS_PGM                          CRM_BYTE(4) 
#define CRM_PROGRAM_MIN_ST_PGM                          CRM_BYTE(5) 
#define CRM_PROGRAM_QUEUE_SIZE_PGM                      CRM_BYTE(6) 

                                                        
/* PROGRAM_CLEAR */
                                     
#define CRO_PROGRAM_CLEAR_LEN                           8
#define CRO_PROGRAM_CLEAR_MODE                          CRO_BYTE(1)
#define CRO_PROGRAM_CLEAR_SIZE                          CRO_DWORD(1)

#define CRM_PROGRAM_CLEAR_LEN                           1

                                                        
/* PROGRAM */

#define CRO_PROGRAM_MAX_SIZE                            ((vuint8)(kXcpMaxCTO-2))
                                           
#define CRO_PROGRAM_LEN                                 2 /* + CRO_PROGRAM_SIZE */ 
#define CRO_PROGRAM_SIZE                                CRO_BYTE(1)
#define CRO_PROGRAM_DATA                                (&CRO_BYTE(2))

#define CRM_PROGRAM_LEN                                 1


/* PROGRAM RESET */

#define CRO_PROGRAM_RESET_LEN                           1

#define CRM_PROGRAM_RESET_LEN                           1

                                                        
/*GET_PGM_PROCESSOR_INFO*/

#define CRO_GET_PGM_PROCESSOR_INFO_LEN                  1

#define CRM_GET_PGM_PROCESSOR_INFO_LEN                  3
#define CRM_GET_PGM_PROCESSOR_INFO_PROPERTIES           CRM_BYTE(1)
#define CRM_GET_PGM_PROCESSOR_INFO_MAX_SECTOR           CRM_BYTE(2)

 
/* GET_SECTOR_INFO */

#define CRO_PROGRAM_GET_SECTOR_INFO_LEN                 3
#define CRO_PROGRAM_GET_SECTOR_INFO_MODE                CRO_BYTE(1)
#define CRO_PROGRAM_GET_SECTOR_INFO_NUMBER              CRO_BYTE(2)

#define CRM_PROGRAM_GET_SECTOR_INFO_LEN                 8
#define CRM_PROGRAM_GET_SECTOR_CLEAR_SEQ_NUM            CRM_BYTE(1)
#define CRM_PROGRAM_GET_SECTOR_PGM_SEQ_NUM              CRM_BYTE(2)
#define CRM_PROGRAM_GET_SECTOR_PGM_METHOD               CRM_BYTE(3)
#define CRM_PROGRAM_GET_SECTOR_SECTOR_INFO              CRM_DWORD(1)
#define CRM_PROGRAM_GET_SECTOR_SECTOR_INFO_WRITE(info)  CRM_DWORD_WRITE(1, info)


/* PROGRAM_PREPARE */
                                   
#define CRO_PROGRAM_PREPARE_LEN                         4
#define CRO_PROGRAM_PREPARE_SIZE                        CRO_WORD(1)

#define CRM_PROGRAM_PREPARE_LEN                         1


/* PROGRAM_FORMAT */

#define CRO_PROGRAM_FORMAT_LEN                          5
#define CRO_PROGRAM_FORMAT_COMPRESSION_METHOD           CRO_BYTE(1)
#define CRO_PROGRAM_FORMAT_ENCRYPTION_METHOD            CRO_BYTE(2)
#define CRO_PROGRAM_FORMAT_PROGRAMMING_METHOD           CRO_BYTE(3)
#define CRO_PROGRAM_FORMAT_ACCESS_METHOD                CRO_BYTE(4)

#define CRM_PROGRAM_FORMAT_LEN                          1


/* PROGRAM_NEXT */

#define CRO_PROGRAM_NEXT_MAX_SIZE                       ((vuint8)(kXcpMaxCTO-2))

#define CRO_PROGRAM_NEXT_LEN                            2 /* + size */
#define CRO_PROGRAM_NEXT_SIZE                           CRO_BYTE(1)
#define CRO_PROGRAM_NEXT_DATA                           (&CRO_BYTE(2))

#define CRM_PROGRAM_NEXT_LEN                            3
#define CRM_PROGRAM_NEXT_ERR_SEQUENCE                   CRM_BYTE(1)
#define CRM_PROGRAM_NEXT_SIZE_EXPECTED_DATA             CRM_BYTE(2)


/* PROGRAM_MAX */

#define CRO_PROGRAM_MAX_MAX_SIZE                        ((vuint8)(kXcpMaxCTO-1))
#define CRO_PROGRAM_MAX_DATA                            (&CRO_BYTE(1))

#define CRM_PROGRAM_MAX_LEN                             1


/* PROGRAM_VERIFY */

#define CRO_PROGRAM_VERIFY_LEN                          8
#define CRO_PROGRAM_VERIFY_MODE                         CRO_BYTE(1)
#define CRO_PROGRAM_VERIFY_TYPE                         CRO_WORD(1)
#define CRO_PROGRAM_VERIFY_VALUE                        CRO_DWORD(1)

#define CRM_PROGRAM_VERIFY_LEN                          1


/* GET_SLAVE_ID */

#define CRO_GET_SLAVE_ID_LEN                            6
#define CRO_GET_SLAVE_ID_SUB_CODE                       CRO_BYTE(1)
#define CRO_GET_SLAVE_ID_X                              CRO_BYTE(2)
#define CRO_GET_SLAVE_ID_C                              CRO_BYTE(3)
#define CRO_GET_SLAVE_ID_P                              CRO_BYTE(4)
#define CRO_GET_SLAVE_ID_MODE                           CRO_BYTE(5)

#define CRM_GET_SLAVE_ID_LEN                            8
#define CRM_GET_SLAVE_ID_X                              CRM_BYTE(1)
#define CRM_GET_SLAVE_ID_C                              CRM_BYTE(2)
#define CRM_GET_SLAVE_ID_P                              CRM_BYTE(3)
#define CRM_GET_SLAVE_ID_CAN_ID_CMD_STIM                CRM_DWORD(1)

                                                        
/* GET_DAQ_ID */
                                   
#define CRO_GET_DAQ_ID_LEN                              3
#define CRO_GET_DAQ_ID_SUB_CODE                         CRO_BYTE(1)
#define CRO_GET_DAQ_ID_DAQ                              CRO_WORD(1)

#define CRM_GET_DAQ_ID_LEN                              8
#define CRM_GET_DAQ_ID_FIXED                            CRM_BYTE(1)
#define CRM_GET_DAQ_ID_ID                               CRM_DWORD(1)


/* SET_DAQ_ID */
                                   
#define CRO_SET_DAQ_ID_LEN                              8
#define CRO_SET_DAQ_ID_SUB_CODE                         CRO_BYTE(1)
#define CRO_SET_DAQ_ID_DAQ                              CRO_WORD(1)
#define CRO_SET_DAQ_ID_ID                               CRO_DWORD(1)

#define CRM_SET_DAQ_ID_LEN                              1

/* SET_SLAVE_PORT */

#define CRO_SET_SLAVE_PORT_LEN                          4
#define CRO_SET_SLAVE_PORT_SUB_CODE                     CRO_BYTE(1)
#define CRO_SET_SLAVE_PORT_PORT                         CRO_WORD(1)

#define CRM_SET_SLAVE_PORT                              1  

#if defined ( XCP_ENABLE_GET_CONNECTION_STATE ) || defined ( XCP_ENABLE_GET_SESSION_STATUS_API )
  #define XCP_DISCONNECTED                              0u
  #define XCP_CONNECTED                                 1u
#endif


/****************************************************************************/
/* Implementation                                                           */
/****************************************************************************/


  #if defined ( XCP_ENABLE_SEND_EVENT ) || defined ( XCP_ENABLE_SERV_TEXT )
    #define EV_BYTE(x)            (xcp.Ev.b[x])
  #endif

  #define CRO_BYTE(x)             (pCmd->b[x])
  #define CRM_BYTE(x)             (xcp.Crm.b[x])

#if defined ( XCP_ENABLE_USE_BYTE_ACCESS )
  #if defined ( XCP_CPUTYPE_LITTLEENDIAN )
    #define CRO_WORD(x)             (((vuint16)pCmd->b[((x)*2)+1] << 8) | ((vuint8)pCmd->b[((x)*2)+0]))
    #define CRO_DWORD(x)            (((vuint32)pCmd->b[((x)*4)+3] << 24) | ((vuint32)pCmd->b[((x)*4)+2] << 16)| ((vuint16)pCmd->b[((x)*4)+1] << 8)| ((vuint8)pCmd->b[((x)*4)+0]))

    #define CRM_WORD(x)             (((vuint16)xcp.Crm.b[((x)*2)+1] << 8) | ((vuint8)xcp.Crm.b[((x)*2)+0]))
    #define CRM_WORD_WRITE(x, d)    {xcp.Crm.b[((x)*2)+0] = ((vuint8)(d) & 0xFF); xcp.Crm.b[((x)*2)+1] = ((vuint8)((vuint16)(d) >> 8) & 0xFF);}
    #define CRM_DWORD(x)            (((vuint32)xcp.Crm.b[((x)*4)+3] << 24) | ((vuint32)xcp.Crm.b[((x)*4)+2] << 16) | ((vuint16)xcp.Crm.b[((x)*4)+1] << 8) | ((vuint8)xcp.Crm.b[((x)*4)+0]) )
    #define CRM_DWORD_WRITE(x, d)   {xcp.Crm.b[((x)*4)+0] = ((vuint8)((vuint32)(d) >> 0) & 0xFF); \
                                     xcp.Crm.b[((x)*4)+1] = ((vuint8)((vuint32)(d) >> 8) & 0xFF); \
                                     xcp.Crm.b[((x)*4)+2] = ((vuint8)((vuint32)(d) >> 16) & 0xFF); \
                                     xcp.Crm.b[((x)*4)+3] = ((vuint8)((vuint32)(d) >> 24) & 0xFF);}
  #else
    #define CRO_WORD(x)             (((vuint16)pCmd->b[((x)*2)+0] << 8) | ((vuint8)pCmd->b[((x)*2)+1]))
    #define CRO_DWORD(x)            (((vuint32)pCmd->b[((x)*4)+0] << 24) | ((vuint32)pCmd->b[((x)*4)+1] << 16)| ((vuint16)pCmd->b[((x)*4)+2] << 8)| ((vuint8)pCmd->b[((x)*4)+3]))

    #define CRM_WORD(x)             (((vuint16)xcp.Crm.b[((x)*2)+0] << 8) | ((vuint8)xcp.Crm.b[((x)*2)+1]))
    #define CRM_WORD_WRITE(x, d)    {xcp.Crm.b[((x)*2)+1] = ((vuint8)(d) & 0xFF); xcp.Crm.b[((x)*2)+0] = ((vuint8)((vuint16)(d) >> 8) & 0xFF);}
    #define CRM_DWORD(x)            (((vuint32)xcp.Crm.b[((x)*4)+0] << 24) | ((vuint32)xcp.Crm.b[((x)*4)+1] << 16) | ((vuint16)xcp.Crm.b[((x)*4)+2] << 8) | ((vuint8)xcp.Crm.b[((x)*4)+3]) )
    #define CRM_DWORD_WRITE(x, d)   {xcp.Crm.b[((x)*4)+3] = ((vuint8)((vuint32)(d) >> 0) & 0xFF); \
                                     xcp.Crm.b[((x)*4)+2] = ((vuint8)((vuint32)(d) >> 8) & 0xFF); \
                                     xcp.Crm.b[((x)*4)+1] = ((vuint8)((vuint32)(d) >> 16) & 0xFF); \
                                     xcp.Crm.b[((x)*4)+0] = ((vuint8)((vuint32)(d) >> 24) & 0xFF);}
  #endif
#else
  #define CRO_WORD(x)               (pCmd->w[x])
  #define CRO_DWORD(x)              (pCmd->dw[x])
  #define CRM_WORD(x)               (xcp.Crm.w[x])
  #define CRM_WORD_WRITE(x, d)      (xcp.Crm.w[x] = (d))
  #define CRM_DWORD(x)              (xcp.Crm.dw[x])
  #define CRM_DWORD_WRITE(x, d)     (xcp.Crm.dw[x] = (d))
#endif




/****************************************************************************/
/* Default data type definitions                                            */
/****************************************************************************/

/* Pointer to far memory */
#if defined ( XCP_MEMORY_FAR )
#else
  #if defined ( MEMORY_FAR )
    #define XCP_MEMORY_FAR MEMORY_FAR
  #else
    #if defined ( V_MEMRAM2_FAR )
      #define XCP_MEMORY_FAR  V_MEMRAM2_FAR
    #else
      #define XCP_MEMORY_FAR
    #endif
  #endif
#endif

/* Far memory qualifier for functions. */
#if defined ( XCP_FAR )
#else
  #if defined ( C_COMP_COSMIC_MCS12X_MSCAN12 )
    /* Always use far access for ApplXcpWrite() and ApplXcpread(). */
    #define XCP_FAR @far
  #else
    #define XCP_FAR
  #endif
#endif

/* RAM */
#if defined ( RAM )
#else
  #define RAM
#endif


/*
   DAQBYTEPTR and MTABYTEPTR may be defined different to BYTEPTR to save memory
   Example:
     #define BYTEPTR     unsigned char *
     #define MTABYTEPTR  huge unsigned char *
     #define DAQBYTEPTR  unsigned char *
*/
#if defined ( DAQBYTEPTR )
#else
  #define DAQBYTEPTR vuint8 XCP_MEMORY_FAR *
#endif

#if defined ( MTABYTEPTR )
#else
  #define MTABYTEPTR vuint8 XCP_MEMORY_FAR *
#endif

/* Pointer type used to point into the xcp structure */
#if defined ( BYTEPTR )
#else
  #define BYTEPTR vuint8 *
#endif

#if defined ( ROMBYTEPTR )
#else
  #define ROMBYTEPTR vuint8 const *
#endif


/****************************************************************************/
/* Checks and default values                                                */
/****************************************************************************/

/* Turn off test instrumentation, if not used */
#if !defined(XCP_ASSERT)
  #define XCP_ASSERT(x) 
#endif
#if !defined(XCP_PRINT)
  #define XCP_PRINT(x) 
#endif
#if !defined(BEGIN_PROFILE)
  #define BEGIN_PROFILE(i)
#endif
#if !defined(END_PROFILE)
  #define END_PROFILE(i)
#endif

/* Check limits of the XCP imnplementation
*/
#if ( kXcpMaxCTO > 255 )
  #error "kXcpMaxCTO must be < 256"
#endif
#if ( kXcpMaxCTO < 0x08 )
  #error "kXcpMaxCTO must be > 0x07"
#endif
#if ( kXcpMaxDTO > 255 )
  #error "kXcpMaxDTO must be < 256"
#endif
#if ( kXcpMaxDTO < 0x08 )
  #error "kXcpMaxDTO must be > 0x07"
#endif

#if defined ( XCP_ENABLE_DAQ )

/* kXcpDaqMemSize must be defined 
*/
  #if defined ( kXcpDaqMemSize )
  #else
    #error "Please define kXcpDaqMemSize"
  #endif

/* Use send queue as default
*/
  #if defined ( XCP_ENABLE_SEND_QUEUE ) || defined ( XCP_DISABLE_SEND_QUEUE )
  #else
    #define XCP_ENABLE_SEND_QUEUE
  #endif 

/*
  Max. size of an object referenced by an ODT entry
  XCP_MAX_ODT_ENTRY_SIZE may be limited 
*/
  #if defined ( XCP_MAX_ODT_ENTRY_SIZE )
  #else
    #if defined ( XCP_ENABLE_DAQ_HDR_ODT_DAQ )
      #define XCP_MAX_ODT_ENTRY_SIZE (kXcpMaxDTO-2)
    #else
      #define XCP_MAX_ODT_ENTRY_SIZE (kXcpMaxDTO-1)
    #endif
  #endif

#else /* XCP_ENABLE_DAQ */
#endif /* XCP_ENABLE_DAQ */



/****************************************************************************/
/* XCP Packet Type Definition                                               */
/****************************************************************************/

typedef struct {
  vuint8 b[kXcpMaxDTO];
  vuint8 l;
} tXcpDto;

typedef union { /* PRQA S 0750 */ /* MD_MSR_18.4 */
  /* There might be a loss of up to 3 bytes. */
  vuint8  b[ ((kXcpMaxCTO + 3) & 0xFFC)      ];
  vuint16 w[ ((kXcpMaxCTO + 3) & 0xFFC) / 2  ];
  vuint32 dw[ ((kXcpMaxCTO + 3) & 0xFFC) / 4 ];
} tXcpCto;

/****************************************************************************/
/* DAQ Lists, Type Definition                                               */
/****************************************************************************/

/* Note:
   - Adressextensions are not used for DAQ
*/

#if defined ( XCP_ENABLE_DAQ )

/* ODT */
/* Size must be even !!! */
typedef struct {

  vuint16 firstOdtEntry;       /* Absolute */
  vuint16 lastOdtEntry;        /* Absolute */


} tXcpOdt;

#if defined( XCP_ENABLE_ODT_SIZE_WORD )
typedef vuint16 tXcpOdtIdx;
typedef vuint16 tXcpOdtCnt;
#else
typedef vuint8 tXcpOdtIdx;
typedef vuint8 tXcpOdtCnt;
#endif

/* DAQ list */
typedef struct {

  tXcpOdtIdx lastOdt;             /* Absolute */
  tXcpOdtIdx firstOdt;            /* Absolute */

  vuint8 flags;        

  #if defined ( kXcpMaxEvent ) && ! defined ( XCP_ENABLE_DAQ_PRESCALER )
  /* Event-Daq association array used */
  #else
  vuint8 eventChannel; 
  #endif

  #if defined ( XCP_ENABLE_DAQ_PRESCALER )
  vuint8 prescaler;  
  vuint8 cycle;     
  #endif

} tXcpDaqList;

#endif /* XCP_ENABLE_DAQ */

/* Dynamic DAQ list structures */
typedef struct {

  vuint8 ActiveTl;                /* Active Transport Layer */

#if defined ( XCP_ENABLE_DAQ )    /* Data Acquisition */

  vuint8          DaqCount;
  tXcpOdtCnt      OdtCount;       /* Absolute count */
  vuint16         OdtEntryCount;  /* Absolute count */

  /* Session configuration id for resume mode */

  /* Event-Daq association array */ 
  #if defined ( kXcpMaxEvent ) && ! defined ( XCP_ENABLE_DAQ_PRESCALER )
  vuint8 EventDaq[kXcpMaxEvent];
  #endif

  union { /* PRQA S 0750 */ /* MD_MSR_18.4 */
    vuint8        b[kXcpDaqMemSize];
    tXcpDaqList   DaqList[kXcpDaqMemSize/sizeof(tXcpDaqList)]; /* ESCAN00096039 */
  } u;

#endif /* XCP_ENABLE_DAQ */

} tXcpDaq;

typedef vuint16 SessionStatusType;

#if defined ( XCP_ENABLE_DAQ )            /* Data Acquisition */

#if defined ( XCP_ENABLE_DAQ_TIMESTAMP )
  #if ( kXcpDaqTimestampSize == DAQ_TIMESTAMP_BYTE )
    typedef vuint8 XcpDaqTimestampType;
    #define XcpDaqTimestampSize 1
  #elif ( kXcpDaqTimestampSize == DAQ_TIMESTAMP_WORD )
    typedef vuint16 XcpDaqTimestampType;
    #define XcpDaqTimestampSize 2
  #elif ( kXcpDaqTimestampSize == DAQ_TIMESTAMP_DWORD )
    typedef vuint32 XcpDaqTimestampType;
    #define XcpDaqTimestampSize 4
  #else
    #error "kXcpDaqTimestampSize not defined. Please define a valid timestamp type!"
  #endif
#endif


  /* Shortcuts */

  /* j is absolute odt number */
  #define DaqListOdtEntryCount(j) ((xcp.pOdt[j].lastOdtEntry-xcp.pOdt[j].firstOdtEntry)+1)
  #define DaqListOdtLastEntry(j)  (xcp.pOdt[j].lastOdtEntry)
  #define DaqListOdtFirstEntry(j) (xcp.pOdt[j].firstOdtEntry)
  #define DaqListOdtStimBuffer(j) (xcp.pOdt[j].pStimBuffer)

  /* n is absolute odtEntry number */
  #define OdtEntrySize(n)         (xcp.pOdtEntrySize[n])
  #define OdtEntryAddr(n)         (xcp.pOdtEntryAddr[n])

   /* i is daq number */
  #define DaqListOdtCount(i)      ((xcp.Daq.u.DaqList[i].lastOdt-xcp.Daq.u.DaqList[i].firstOdt)+1)
  #define DaqListLastOdt(i)       xcp.Daq.u.DaqList[i].lastOdt
  #define DaqListFirstOdt(i)      xcp.Daq.u.DaqList[i].firstOdt
  #define DaqListFirstPid(i)      xcp.Daq.u.DaqList[i].firstOdt
  #define DaqListFlags(i)         xcp.Daq.u.DaqList[i].flags
  #define DaqListEventChannel(i)  xcp.Daq.u.DaqList[i].eventChannel
  #define DaqListPrescaler(i)     xcp.Daq.u.DaqList[i].prescaler 
  #define DaqListCycle(i)         xcp.Daq.u.DaqList[i].cycle


#endif /* XCP_ENABLE_DAQ */


/****************************************************************************/
/* Checksum, Type Definition                                                */
/****************************************************************************/
#if defined ( XCP_ENABLE_CHECKSUM )
  #if ( kXcpChecksumMethod == XCP_CHECKSUM_TYPE_ADD11 ) || \
      ( kXcpChecksumMethod == XCP_CHECKSUM_TYPE_ADD12 ) || \
      ( kXcpChecksumMethod == XCP_CHECKSUM_TYPE_ADD14 ) || \
      ( kXcpChecksumMethod == XCP_CHECKSUM_TYPE_CRC16 ) || \
      ( kXcpChecksumMethod == XCP_CHECKSUM_TYPE_CRC16CCITT ) || \
      ( kXcpChecksumMethod == XCP_CHECKSUM_TYPE_CRC32 )
  #define tXcpChecksumAddSize 1
  typedef vuint8 tXcpChecksumAddType;    /* Data type (width) of the data to be added.  */
  #endif
  #if ( kXcpChecksumMethod == XCP_CHECKSUM_TYPE_ADD22 ) || \
      ( kXcpChecksumMethod == XCP_CHECKSUM_TYPE_ADD24 )
  #define tXcpChecksumAddSize 2
  typedef vuint16 tXcpChecksumAddType;   /* Data type (width) of the data to be added.  */
  #endif
  #if ( kXcpChecksumMethod == XCP_CHECKSUM_TYPE_ADD44 )
  #define tXcpChecksumAddSize 4
  typedef vuint32 tXcpChecksumAddType;   /* Data type (width) of the data to be added.  */
  #endif

  #if ( kXcpChecksumMethod == XCP_CHECKSUM_TYPE_ADD11 )
  #define tXcpChecksumSumSize 1
  typedef vuint8 tXcpChecksumSumType;    /* Data type (width) of the actual checksum. */
  #endif
  #if ( kXcpChecksumMethod == XCP_CHECKSUM_TYPE_ADD12 ) || \
      ( kXcpChecksumMethod == XCP_CHECKSUM_TYPE_ADD22 ) || \
      ( kXcpChecksumMethod == XCP_CHECKSUM_TYPE_CRC16 ) || \
      ( kXcpChecksumMethod == XCP_CHECKSUM_TYPE_CRC16CCITT )
  #define tXcpChecksumSumSize 2
  typedef vuint16 tXcpChecksumSumType;   /* Data type (width) of the actual checksum. */
  #endif
  #if ( kXcpChecksumMethod == XCP_CHECKSUM_TYPE_ADD14 ) || \
      ( kXcpChecksumMethod == XCP_CHECKSUM_TYPE_ADD24 ) || \
      ( kXcpChecksumMethod == XCP_CHECKSUM_TYPE_ADD44 ) || \
      ( kXcpChecksumMethod == XCP_CHECKSUM_TYPE_CRC32 ) 
  #define tXcpChecksumSumSize 4
  typedef vuint32 tXcpChecksumSumType;   /* Data type (width) of the actual checksum. */
  #endif
#endif


/****************************************************************************/
/* XCP Segment CAL parameters                                               */
/* Sement info                                                              */
/****************************************************************************/

#if defined ( XCP_ENABLE_PAGE_INFO )
typedef struct {
    vuint8  SegmentInfoMaxPages; 
    vuint8  SegmentInfoInitSegment; 
    vuint8  SegmentInfoAddressExtension;
    vuint8  SegmentInfoMaxMapping;
    vuint8  SegmentInfoMode;
    vuint8  SegmentPageProperties[kXcpMaxPages];
    vuint8  SegmentPageAktiv[kXcpMaxPages];        /* 1=aktiv, 0=deaktiv. */
    vuint8  SegmentPageMode[kXcpMaxPages];         /* 1=ECU, 2=XCP */
    vuint32 SegmentInfoMapping;
} tXcpSegmentInfo;
#endif


/****************************************************************************/
/* XCP Driver Variables, Type Definition                                    */
/****************************************************************************/

/* Return values */
#define XCP_CMD_DENIED              0
#define XCP_CMD_OK                  1
#define XCP_CMD_PENDING             2
#define XCP_CMD_SYNTAX              3
#define XCP_CMD_BUSY                4
#define XCP_CMD_UNKNOWN             5
#define XCP_CMD_OUT_OF_RANGE        6
#define XCP_MODE_NOT_VALID          7
#define XCP_CMD_ERROR               0xFF

#define XCP_OK                      0
#define XCP_NOT_OK                  1

/* Return values for XcpEvent() */
#define XCP_EVENT_NOP               0x00u   /* Inactive (DAQ not running, Event not configured) */
#define XCP_EVENT_DAQ               0x01u   /* DAQ active */
#define XCP_EVENT_DAQ_OVERRUN       0x02u   /* DAQ queue overflow */
#define XCP_EVENT_DAQ_TIMEOUT       0x04u   /* Timeout supervision violation */
#define XCP_EVENT_STIM              0x08u   /* STIM active */
#define XCP_EVENT_STIM_OVERRUN      0x10u   /* STIM data not available */

/* Bitmasks for xcp.SendStatus */
#define XCP_CRM_REQUEST             0x01u
#define XCP_DTO_REQUEST             0x02u
#define XCP_EVT_REQUEST             0x04u
#define XCP_CRM_PENDING             0x10u
#define XCP_DTO_PENDING             0x20u
#define XCP_EVT_PENDING             0x40u
#define XCP_SEND_PENDING            (XCP_DTO_PENDING|XCP_CRM_PENDING|XCP_EVT_PENDING)

typedef struct {
  /* Crm has to be the first object of this structure !! (refer to XcpInit()) */

  tXcpCto Crm;                           /* RES,ERR Message buffer */
  vuint8  CrmLen;                        /* RES,ERR Message length */

#if defined ( XCP_ENABLE_SEND_EVENT ) || defined ( XCP_ENABLE_SERV_TEXT )
  tXcpCto Ev;                            /* EV,SERV Message buffer */
  vuint8 EvLen;                          /* EV,SERV Message length */
#endif
  
  SessionStatusType SessionStatus;

  MTABYTEPTR Mta;                        /* Memory Transfer Address */


#if defined ( XCP_ENABLE_SEED_KEY )
  vuint8 ProtectionStatus;                /* Resource Protection Status */
#endif

#if defined ( XCP_ENABLE_CHECKSUM ) && !defined ( XCP_ENABLE_CUSTOM_CRC )
  vuint16             CheckSumSize;       /* Counter for checksum calculation */
  tXcpChecksumSumType CheckSum;           /* Actual checksum */
#endif

  /*
    Dynamic DAQ list structures
    This structure should be stored in resume mode
  */
  tXcpDaq Daq;


#if defined ( XCP_ENABLE_DAQ )            /* Data Acquisition */

  tXcpOdt       *pOdt;
  DAQBYTEPTR    *pOdtEntryAddr;
  vuint8        *pOdtEntrySize;
  
  /* Transmit Queue */
  #if defined ( XCP_ENABLE_SEND_QUEUE )
  tXcpDto *pQueue;
  vuint16  QueueSize;
  vuint16  QueueLen;
  vuint16  QueueRp;
  #endif

  /* Transmit Status */
  #if defined ( XCP_ENABLE_SEND_QUEUE)
  volatile vuint8 SendStatus;
  #endif

  /* Pointer for SET_DAQ_PTR */
  vuint16 DaqListPtr;           
    
    
#endif /* XCP_ENABLE_DAQ */

} tXcpData;


/***************************************************************************/
/* External Declarations                                                   */
/***************************************************************************/

extern RAM tXcpData xcp;
/*******************************************************************************
* External 8 Bit Constants
*******************************************************************************/

V_MEMROM0 extern const  vuint8 kXcpMainVersion;
V_MEMROM0 extern const  vuint8 kXcpSubVersion;
V_MEMROM0 extern const  vuint8 kXcpReleaseVersion;



/****************************************************************************/
/* Prototypes                                                               */
/****************************************************************************/


/* Important external functions of xcp.c */
/*-----------------------------------------*/


/* Initialization and deinitialization functions for the XCP Protocol Layer. */
extern void XcpInit( void );
extern void XcpExit( void );

/* Trigger a XCP data acquisition or stimulation event */
/* Returns an error status XCP_EVENT_xxxx */
extern vuint8 XcpEvent( vuint8 event );

/* Check if a XCP stimulation event can perform or delete the buffers */
/* Returns 1 (TRUE) if new stimulation data is available */

/* Call the XCP command processor. */
extern void XcpCommand( const vuint32* pCommand );

/* Transmit Notification */
/* Confirmation of the transmit request by ApplXcpSend(). */
/* Returns 0 when the XCP driver is idle */
extern vuint8 XcpSendCallBack( void );

/* Background Loop */
/* Return 1 (TRUE) if anything is still pending */
/* Used only if Checksum Calculation or EEPROM Programming is required */
extern vuint8 XcpBackground( void );


/*-----------------------------------------------------------------------------------*/
/* Functions or Macros that have to be provided externally to the XCP Protocol Layer */
/*-----------------------------------------------------------------------------------*/


#if defined ( XCP_TRANSPORT_LAYER_TYPE_CAN )
    #define ApplXcpSend(len, msg)  XcpCanSend(len, msg)
    #if defined ( ApplXcpSendFlush )
    #else
      #define ApplXcpSendFlush()
    #endif
    #define ApplXcpInit()          XcpCanInit()
    #define ApplXcpBackground()    XcpCanBackground()
#endif

 
/* Transmission Request for a XCP Packet */
#if defined ( ApplXcpSend )
#else
extern void ApplXcpSend( vuint8 len, const BYTEPTR msg );
#endif

/* Flush the transmit buffer if there is one implemented in ApplXcpSend() */
#if defined ( ApplXcpSendFlush )
#else
extern void ApplXcpSendFlush( void );
#endif

/* Generate a native pointer from XCP address extension and address */
#if defined ( ApplXcpGetPointer )
#else
extern MTABYTEPTR ApplXcpGetPointer( vuint8 addr_ext, vuint32 addr );
#endif

#if defined ( XCP_ENABLE_MEM_ACCESS_BY_APPL )
extern vuint8 ApplXcpRead( vuint32 addr );
extern void XCP_FAR ApplXcpWrite( vuint32 addr, vuint8 data );
#endif

#if defined ( XCP_ENABLE_CALIBRATION_MEM_ACCESS_BY_APPL ) || defined ( XCP_ENABLE_MEM_ACCESS_BY_APPL )
  #if defined ( XCP_ENABLE_CHECKSUM )
     #if ( kXcpChecksumMethod == XCP_CHECKSUM_TYPE_ADD22 ) || \
         ( kXcpChecksumMethod == XCP_CHECKSUM_TYPE_ADD24 ) || \
         ( kXcpChecksumMethod == XCP_CHECKSUM_TYPE_ADD44 ) || \
         defined ( XCP_ENABLE_CALIBRATION_MEM_ACCESS_BY_APPL )
extern tXcpChecksumAddType ApplXcpReadChecksumValue( vuint32 addr );
    #endif
  #endif
#endif


#if defined ( XCP_ENABLE_CALIBRATION_MEM_ACCESS_BY_APPL ) && !defined ( XCP_ENABLE_MEM_ACCESS_BY_APPL )
extern vuint8 ApplXcpCalibrationWrite(MTABYTEPTR addr, vuint8 size, const BYTEPTR data);
extern vuint8 ApplXcpCalibrationRead(MTABYTEPTR addr, vuint8 size, BYTEPTR data);
#endif

/* Application specific initialization function (called by XcpInit() ). */
#if defined ( ApplXcpInit )
#else
extern void ApplXcpInit( void );
#endif

/* Application specific background ground loop (called by XcpBackground() ). */
#if defined ( ApplXcpBackground )
#else
extern void ApplXcpBackground( void );
#endif

/* Enable interrupts */
#if defined ( ApplXcpInterruptEnable )
#else
extern void ApplXcpInterruptEnable( void );
#endif

/* Disable interrupts */
#if defined ( ApplXcpInterruptDisable )
#else
extern void ApplXcpInterruptDisable( void );
#endif


/* Some available utility functions */
/*----------------------------------*/

/* Force a XCP disconnect */
extern void XcpDisconnect( void );

/* Set size of transfer objects */
void XcpSetActiveTl( vuint8 MaxCto, vuint8 MaxDto, vuint8 ActiveTl );
vuint8 XcpGetActiveTl( void );

/* Send a pending XCP response packet (RES). */
/* To be used after a XCP_CMD_PENDING from EEPROM or FLASH programming. */
extern void XcpSendCrm( void );

/* Send a XCP event (EV) or service request (SERV) message */ 
#if defined ( XCP_ENABLE_SEND_EVENT )
extern void XcpSendEvent( vuint8 evc, const BYTEPTR c, vuint8 len);
#endif

/* Send a text message */
/* Implement print and putchar into a XCP SERV/SERV_TEXT message */
#if defined ( XCP_ENABLE_SERV_TEXT )
  #if defined ( XCP_ENABLE_SERV_TEXT_PUTCHAR )
extern void XcpPutchar( const vuint8 c );
    #if defined ( XCP_ENABLE_SERV_TEXT_PRINT )
extern void XcpPrint( const vuint8 *str );
      #if defined ( XCP_ENABLE_SERV_TEXT_PRINTF )
extern void XcpPrintf( const vuint8 *str, ... );
      #endif
    #endif
  #endif
#endif


/* Functions that may have be provided externally depending on options */
/*---------------------------------------------------------------------*/

/* Utility functions from xcp.c */
/*------------------------------*/

/* Override option for the memory transfer function */
/* May be used for optimization */
/* #define XcpMemCpy, #define XcpMemSet to disable the implementation in xcp.c */
#if defined ( XcpMemCpy ) || defined ( C_COMP_COSMIC_MCS12X_MSCAN12 )
#else
extern void XcpMemCpy( DAQBYTEPTR dest, const DAQBYTEPTR src, vuint8 n );
#endif
#if defined ( XcpMemSet )
#else
extern void XcpMemSet( BYTEPTR p, vuint16 n, vuint8 b );
#endif

/* Send a DTO */
/* Can be redefined to meet DMA requirements */
#if defined ( XCP_ENABLE_DAQ )
  #if defined ( XcpSendDto )
  /* XcpSendDto is redefined */
  #else
extern void XcpSendDto( const tXcpDto *dto );
  #endif
#endif

/* Resolve a transmit stall condition in XcpPutchar() or XcpSendEvent() */
/* Returns true (!=0) if successfull */
#if defined ( XCP_ENABLE_SEND_EVENT ) || defined ( XCP_ENABLE_SERV_TEXT_PUTCHAR )
  #if defined ( XCP_ENABLE_SEND_QUEUE )
    #if defined ( ApplXcpSendStall )
    #else
extern vuint8 ApplXcpSendStall( void );
    #endif
  #endif
#endif

/* Check addresses for valid write access */
/* Returns 0 (false) if access denied */
/* Used only, if write protection of memory areas is required */

/* Check addresses for valid read access */
/* Returns 0 (false) if access denied */
/* Used only, if read protection of memory areas is required */

/* Check addresses for valid read/write access */
/* Returns 0 (false) if access denied */
/* Used only, if DAQ protection of memory areas is required */
#if defined ( XCP_ENABLE_DAQ )
#endif

/* Calculate checksum for a memory range */
/* Returns 0 (false) if access denied */
/* Used only, if read protection of memory areas is required */
#if defined ( XCP_ENABLE_CHECKSUM ) && defined ( XCP_ENABLE_CUSTOM_CRC )
  #if defined ( ApplXcpCalculateChecksum ) /* Not defined as macro */
  #else
extern vuint8 ApplXcpCalculateChecksum( ROMBYTEPTR pMemArea, BYTEPTR pRes, vuint32 length );
  #endif
#endif

/* Check addresses for valid programming access */
/* Returns 0 (false) if access denied */
/* Used only, if programming protection of memory areas is required */

/* DAQ resume */

/* DAQ Timestamp */
#if defined ( XCP_ENABLE_DAQ_TIMESTAMP )
  #if defined ( ApplXcpGetTimestamp )
  /* ApplXcpGetTimestamp is redefined */
  #else
extern XcpDaqTimestampType ApplXcpGetTimestamp( void );
  #endif
#endif



/* Flash Programming by Flash Kernel */


/* Flash Programming */


/* RAM/ROM Switching */
#if defined ( XCP_ENABLE_CALIBRATION_PAGE )

extern vuint8 ApplXcpGetCalPage( vuint8 segment, vuint8 mode ); 
extern vuint8 ApplXcpSetCalPage( vuint8 segment, vuint8 page, vuint8 mode);

/* extern void ApplXcpInitCalPage( void ); */
  #if defined ( XCP_ENABLE_PAGE_COPY )
extern vuint8 ApplXcpCopyCalPage( vuint8 srcSeg, vuint8 srcPage, vuint8 destSeg, vuint8 destPage );
/* Returns:
   XCP_CMD_OK    
   XCP_CMD_PENDING - call XcpSendCrm when done
   XCP_CMD_ERROR 
*/
  #endif
#endif
#if defined ( XCP_ENABLE_PAGE_FREEZE )
extern void ApplXcpSetFreezeMode( vuint8 segment, vuint8 mode );
extern vuint8 ApplXcpGetFreezeMode( vuint8 segment );
#endif

/* Seed & Key */
#if defined ( XCP_ENABLE_SEED_KEY )

extern vuint8 ApplXcpGetSeed( const vuint8 resource, vuint8 *seed );
extern vuint8 ApplXcpUnlock( const vuint8 *key, const vuint8 length );

#endif

/* User defined service of GET_ID */
#if defined ( XCP_ENABLE_GET_ID_GENERIC )
extern vuint32 ApplXcpGetIdData( MTABYTEPTR *pData, vuint8 id );
#endif

/* EEPROM Programing */


/* User defined service */ 
#if defined ( XCP_ENABLE_USER_COMMAND )
/* Return values for ApplXcpUserService:
 XCP_CMD_OK      - Done
 XCP_CMD_PENDING - Pending, call XcpSendCrm when done
 XCP_CMD_SYNTAX  - Error
*/
extern vuint8 ApplXcpUserService( const BYTEPTR pCmd );
#endif

/* Transport Layer service */ 


#if defined ( XCP_ENABLE_VERSION_INFO_API )
extern void XcpGetVersionInfo(Std_VersionInfoType *XcpVerInfoPtr);
#endif

#if defined ( XCP_ENABLE_GET_CONNECTION_STATE ) || defined ( XCP_ENABLE_GET_SESSION_STATUS_API )
/* Get the connection state of the XCP Protocol Layer */
extern vuint8 XcpGetState( void );
#endif

#if defined ( XCP_ENABLE_GET_SESSION_STATUS_API )
/* Get the session state of the XCP Protocol Layer */
extern SessionStatusType XcpGetSessionStatus( void );
#endif


#if defined ( XCP_ENABLE_GET_XCP_DATA_POINTER )
extern void XcpGetXcpDataPointer( RAM tXcpData ** pXcpData );
#endif



#if defined ( XCP_ENABLE_TESTMODE )

/****************************************************************************/
/* Test                                                                     */
/****************************************************************************/

extern vuint8 gDebugLevel;

  #if defined ( ApplXcpPrint )
 /* ApplXcpPrint is a macro */
  #else
extern void ApplXcpPrint( const vsint8 *str, ... );
  #endif

extern void XcpPrintDaqList( vuint8 daq );
#endif /* XCP_ENABLE_TESTMODE */




/*****************************************************************************/
/* Consistency and limit checks ( XCP Protocol Layer specific )              */
/*****************************************************************************/

/* The test mode must not be used with XCP Professional.  */



/* Check consistency of DAQ switch */

#if defined ( XCP_ENABLE_DAQ ) && defined ( XCP_DISABLE_DAQ )
  #error "XCP consistency error: DAQ must be either enabled or disabled."
#endif
#if defined ( XCP_ENABLE_DAQ ) || defined ( XCP_DISABLE_DAQ )
#else
  #error "XCP consistency error: DAQ must be enabled or disabled."
#endif

/* Check consistency of send queue */

#if defined ( XCP_ENABLE_SEND_QUEUE ) && defined ( XCP_DISABLE_SEND_QUEUE )
  #error "XCP consistency error: Send queue must be either enabled or disabled."
#endif
#if defined ( XCP_ENABLE_SEND_QUEUE ) || defined ( XCP_DISABLE_SEND_QUEUE )
#else
  #error "XCP consistency error: Send queue must be enabled or disabled."
#endif
#if defined ( XCP_ENABLE_SEND_QUEUE ) && defined ( XCP_DISABLE_DAQ )
  #error "XCP consistency error: Send queue cannot be used without DAQ."
#endif

/* Check consistency of communictaion mode info */

#if defined ( XCP_ENABLE_COMM_MODE_INFO ) && defined ( XCP_DISABLE_COMM_MODE_INFO )
  #error "XCP consistency error: Communictaion mode info must be either enabled or disabled."
#endif
#if defined ( XCP_ENABLE_COMM_MODE_INFO ) || defined ( XCP_DISABLE_COMM_MODE_INFO )
#else
  #error "XCP consistency error: Communictaion mode info must be enabled or disabled."
#endif

/* Check service request */

#if defined ( XCP_ENABLE_SERV_TEXT ) && defined ( XCP_DISABLE_SERV_TEXT )
  #error "XCP consistency error: Service request must be either enabled or disabled."
#endif
#if defined ( XCP_ENABLE_SERV_TEXT ) || defined ( XCP_DISABLE_SERV_TEXT )
#else
  #error "XCP consistency error: Service request must be enabled or disabled."
#endif
#if defined ( XCP_ENABLE_SERV_TEXT ) && defined ( XCP_DISABLE_SERV_TEXT_PUTCHAR )
  #error "XCP consistency error: Without XcpPutchar is no service request possible."
#endif

/* Check service request XcpPutchar */

#if defined ( XCP_ENABLE_SERV_TEXT_PUTCHAR ) && defined ( XCP_DISABLE_SERV_TEXT_PUTCHAR )
  #error "XCP consistency error: XcpPutchar function must be either enabled or disabled."
#endif
#if defined ( XCP_ENABLE_SERV_TEXT_PUTCHAR ) || defined ( XCP_DISABLE_SERV_TEXT_PUTCHAR )
#else
  #error "XCP consistency error: XcpPutchar function must be enabled or disabled."
#endif
#if defined ( XCP_DISABLE_SERV_TEXT ) && defined ( XCP_ENABLE_SERV_TEXT_PUTCHAR )
  #error "XCP consistency error: XcpPutchar function can only be used with service requests."
#endif

/* check service request XcpPutchar */

#if defined ( XCP_ENABLE_SERV_TEXT_PRINT ) && defined ( XCP_DISABLE_SERV_TEXT_PRINT )
  #error "XCP consistency error: XcpPrint function must be either enabled or disabled."
#endif
#if defined ( XCP_ENABLE_SERV_TEXT_PRINT ) || defined ( XCP_DISABLE_SERV_TEXT_PRINT )
#else
  #error "XCP consistency error: XcpPrint function must be enabled or disabled."
#endif
#if defined ( XCP_ENABLE_SERV_TEXT ) && defined ( XCP_DISABLE_SERV_TEXT_PUTCHAR )
  #error "XCP consistency error: XcpPrint requires XcpPutchar function."
#endif

/* Check consistency of DAQ header ODT */
#if defined(XCP_ENABLE_DAQ) 
  #if defined ( XCP_ENABLE_DAQ_HDR_ODT_DAQ ) && defined ( XCP_DISABLE_DAQ_HDR_ODT_DAQ )
    #error "XCP consistency error: DAQ_HDR_ODT_DAQ must be either enabled or disabled."
  #endif
  #if defined ( XCP_ENABLE_DAQ_HDR_ODT_DAQ ) || defined ( XCP_DISABLE_DAQ_HDR_ODT_DAQ )
  #else
    #error "XCP consistency error: DAQ_HDR_ODT_DAQ must be enabled or disabled."
  #endif
#endif

/* Check consistency of Page switching */

#if defined ( XCP_ENABLE_CALIBRATION_PAGE ) && defined ( XCP_DISABLE_CALIBRATION_PAGE )
  #error "XCP consistency error: Page switching must be either enabled or disabled."
#endif
#if defined ( XCP_ENABLE_CALIBRATION_PAGE ) || defined ( XCP_DISABLE_CALIBRATION_PAGE )
#else
  #error "XCP consistency error: Page switching must be enabled or disabled."
#endif

/* Check range of kXcpStationIdLength */

#if defined ( kXcpStationIdLength )
  #if ( kXcpStationIdLength > 0xFF )
    #error "XCP error: kXcpStationIdLength must be < 256."
  #endif
#endif

/* Check range of kXcpStimOdtCount */


#if defined ( XCP_ENABLE_DAQ )

  /* Check range of kXcpDaqMemSize */

  #if defined ( kXcpDaqMemSize )
    #if ( kXcpDaqMemSize > 0xFFFF )
      #error "XCP error: kXcpDaqMemSize must be <= 0xFFFF."
    #endif
  #endif

  /* Check range of kXcpSendQueueMinSize. */

  #if defined ( kXcpSendQueueMinSize ) 
    #if ( kXcpSendQueueMinSize > 0xFF )
      #error "XCP error: kXcpSendQueueMinSize must be <= 0xFF."
    #endif
  #endif

  /* Check range of kXcpMaxEvent */
  #if defined ( kXcpMaxEvent ) 
    #if ( kXcpMaxEvent > 0xFF )
      #error "XCP error: kXcpMaxEvent must be <= 0xFF."
    #endif
  #endif

  /* Check XCP_ENABLE_ODT_SIZE_WORD in combination with XCP_ENABLE_DAQ_HDR_ODT_DAQ */
  #if defined ( XCP_ENABLE_ODT_SIZE_WORD ) 
    #if defined ( XCP_ENABLE_DAQ_HDR_ODT_DAQ )
    #else
      #error "XCP error: If XCP_ENABLE_ODT_SIZE_WORD is enabled, XCP_ENABLE_DAQ_HDR_ODT_DAQ must be enabled as well."
    #endif
  #endif

#endif /* defined ( XCP_ENABLE_DAQ ) */

#if defined ( XCP_ENABLE_CHECKSUM )

  /* Check configuration of kXcpChecksumMethod */
  #if defined ( kXcpChecksumMethod )
    #if ( kXcpChecksumMethod == XCP_CHECKSUM_TYPE_ADD11 ) || \
        ( kXcpChecksumMethod == XCP_CHECKSUM_TYPE_ADD12 ) || \
        ( kXcpChecksumMethod == XCP_CHECKSUM_TYPE_ADD14 ) || \
        ( kXcpChecksumMethod == XCP_CHECKSUM_TYPE_ADD22 ) || \
        ( kXcpChecksumMethod == XCP_CHECKSUM_TYPE_ADD24 ) || \
        ( kXcpChecksumMethod == XCP_CHECKSUM_TYPE_ADD44 ) || \
        ( kXcpChecksumMethod == XCP_CHECKSUM_TYPE_CRC32 ) || \
        ( kXcpChecksumMethod == XCP_CHECKSUM_TYPE_CRC16CCITT )
    #else
      #error "XCP error: Checksum calculation method not supported."
    #endif
  #endif

  /* Check configuration of kXcpChecksumBlockSize. */
  #if defined ( kXcpChecksumBlockSize )
    #if ( kXcpChecksumBlockSize > 0xFFFF )
      #error "XCP error: Checksum block size is limited to a maximum of 0xFFFF."
    #endif
    #if ( kXcpChecksumMethod == XCP_CHECKSUM_TYPE_ADD22 ) || \
        ( kXcpChecksumMethod == XCP_CHECKSUM_TYPE_ADD24 )
      #if ((kXcpChecksumBlockSize % 2) != 0 )
        #error "XCP error: The blocksize must be modulo 2."
      #endif
    #endif
    #if ( kXcpChecksumMethod == XCP_CHECKSUM_TYPE_ADD44 )
      #if ((kXcpChecksumBlockSize % 4) != 0 )
        #error "XCP error: The blocksize must be modulo 4."
      #endif
    #endif
  #endif

    #if ( kXcpChecksumMethod == XCP_CHECKSUM_TYPE_CRC32 )
      #error "XCP error: Checksum calculation method not supported."
    #endif

#endif /* defined ( XCP_ENABLE_CHECKSUM ) */

#if defined ( XCP_ENABLE_DAQ_TIMESTAMP )

  /* Check configuration of kXcpDaqTimestampUnit. */

  #if defined ( kXcpDaqTimestampUnit )
    #if ( (kXcpDaqTimestampUnit >> 4) > 9 ) || ( (kXcpDaqTimestampUnit & 0x0F) > 0 )
      #error "XCP error: the value of kXcpDaqTimestampUnit is not valid."
    #endif
  #endif

  /* Check configuration of kXcpDaqTimestampTicksPerUnit. */

  #if defined ( kXcpDaqTimestampTicksPerUnit )
    #if ( (kXcpDaqTimestampTicksPerUnit > 0xFFFF) || (kXcpDaqTimestampTicksPerUnit == 0) )
      #error "XCP error: illegal range of kXcpDaqTimestampTicksPerUnit: 0 < kXcpDaqTimestampTicksPerUnit <= 0xFFFF."
    #endif
  #endif

  /* Check for configuration of kXcpDaqTimestampSize */
  #if defined ( kXcpDaqTimestampSize )
    #if ( kXcpDaqTimestampSize != DAQ_TIMESTAMP_BYTE ) && ( kXcpDaqTimestampSize != DAQ_TIMESTAMP_WORD ) && ( kXcpDaqTimestampSize != DAQ_TIMESTAMP_DWORD )
      #error "XCP error: Please define kXcpDaqTimestampSize to either DAQ_TIMESTAMP_BYTE, DAQ_TIMESTAMP_WORD or DAQ_TIMESTAMP_DWORD"
    #endif
  #endif

#endif

/* Check range of service request kXcpMaxSegment. */

#if defined ( XCP_ENABLE_PAGE_INFO )
  #if defined ( kXcpMaxSegment ) 
    #if  ( ( kXcpMaxSegment > 0xFF ) || ( kXcpMaxSegment == 0x00 ) )
      #error "XCP error: kXcpMaxSegment must be <= 0xFF and > 0x00."
    #endif
  #endif
#endif

/* Check range of service request kXcpProgramMaxSector. */


/* Check if option MODIFY_BITS is valid */

	
#ifdef __cplusplus
}
#endif

#endif /* ! defined ( __XCP_H_ ) */

