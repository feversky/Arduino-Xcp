#include "XcpCfg.h"


#ifdef __cplusplus
extern "C" {
#endif

/* 
Bit
7: CONSISTENCY_DAQ
6: CONSISTENCY_EVENT
5: x
4: x
3: STIM
2: DAQ
1: x
0: x
 */
vuint8 kXcpEventDirection[kXcpMaxEvent] = {
    0b00000100, 0b00000100
};

vuint8 kXcpEventNameLength[kXcpMaxEvent] = {
    5, 6
};

vuint8* kXcpEventName[kXcpMaxEvent] = {
    "10ms", "100ms"
};

vuint8 kXcpEventCycle[kXcpMaxEvent] = {
    10, 100 /* unit: ms */
};

/* 
0 0 0 0 EVENT_CHANNEL _TIME_UNIT_1NS 1 NS = 1 nanosecond = 10-9 second
0 0 0 1 EVENT_CHANNEL _TIME_UNIT_10NS
0 0 1 0 EVENT_CHANNEL _TIME_UNIT_100NS
0 0 1 1 EVENT_CHANNEL _TIME_UNIT_1US 1 US = 1 microsecond = 10-6 second
0 1 0 0 EVENT_CHANNEL _TIME_UNIT_10US
0 1 0 1 EVENT_CHANNEL _TIME_UNIT_100US
0 1 1 0 EVENT_CHANNEL _TIME_UNIT_1MS 1 MS = 1 millisecond = 10-3 second
0 1 1 1 EVENT_CHANNEL _TIME_UNIT_10MS
1 0 0 0 EVENT_CHANNEL _TIME_UNIT_100MS
1 0 0 1 EVENT_CHANNEL _TIME_UNIT_1S 1 S = 1 second = 1 second
1 0 1 0 EVENT_CHANNEL _TIME_UNIT_1PS 1 PS = 1 picosecond = 10-12 second
1 0 1 1 EVENT_CHANNEL _TIME_UNIT_10PS
1 1 0 0 EVENT_CHANNEL _TIME_UNIT_100PS
 */
vuint8 kXcpEventUnit[kXcpMaxEvent] = {
    6<<4, 6<<4
};

#ifdef __cplusplus
}
#endif