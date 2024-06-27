#pragma once
#include <inttypes.h>
#include <stdlib.h>

#define OPENAVL_STRUCT __attribute__((packed, aligned(1)))


#define OPENAVL_AVL_DATA_STRUCT_VERSION 1
#define OPENAVL_MAX_PKG_SIZE 4095 //12 bits

namespace OAVL
{

typedef struct __extraGpsData__{
    // uint32_t speed      : 9;
    // uint32_t heading    : 9;
    // uint32_t eastWest   : 1;
    // uint32_t northSouth : 1;
    // uint32_t satelites  : 4;
    // uint32_t hdop       : 6;
    // uint32_t gpsStat   : 2; //0: no gps. 1: 2D_Fix, 2:3D_fix

    uint32_t data;

    void setSpeed(uint16_t speed){
        data = (data & 0x007FFFFF) | (speed &0x1FF)<<23;
    }

    void setHeading(uint16_t heading){
        data = (data & 0xFF803FFF) | (heading &0x1FF) <<14;
    }

    void setNorthSouth(uint8_t isNorth){
        data = (data & 0xFFFFDFFF) | (isNorth & 0x1) <<13;
    }

    void setEastWest(uint8_t isEast){
         data = (data & 0xFFFFEFFF) | (isEast & 0x1) <<12;
    }

    void setSatelites(uint8_t satelites){
         data = (data & 0xFFFFF0FF) | (satelites & 0xF) <<8;
    }

    void setHdop(uint8_t hdop){
         data = (data & 0xFFFFFF03) | (hdop & 0x3F) <<2;
    }

    void setGpsState(uint8_t state){
         data = (data & 0xFFFFFFFC) | (state & 0x03);
    }

    __extraGpsData__(uint32_t data):data(data){}
}OPENAVL_STRUCT extraGpsData_t;

typedef struct __gpsData__ {
    uint32_t timestamp;
    int32_t lat;
    int32_t lon;
    extraGpsData_t extraGpsData;

    __gpsData__()  // Default constructor
        : timestamp ( 0 ),
          lat ( 0 ),
          lon ( 0 ),
          extraGpsData(0)
           {}

    __gpsData__ ( __gpsData__& gps )
        : timestamp ( gps.timestamp ),
          lat ( gps.lat ),
          lon ( gps.lon ),
          extraGpsData(gps.extraGpsData)
          {}

} OPENAVL_STRUCT gpsData_t;


typedef struct __trackId__ {
    uint16_t deviceId;
    uint8_t clientId;

    __trackId__() : deviceId ( 0 ), clientId ( 0 ) {}
    __trackId__ ( uint16_t dId, uint16_t cId ) : deviceId ( dId ), clientId ( cId ) {}
    __trackId__ ( __trackId__& tId ) : deviceId ( tId.deviceId ), clientId ( tId.clientId ) {}
} OPENAVL_STRUCT trackId_t;

typedef struct __avlHeader__{
    uint16_t structVersion : 4;
    uint16_t pkgLen: 12;

    __avlHeader__(uint16_t pkgLen) : structVersion(OPENAVL_AVL_DATA_STRUCT_VERSION), pkgLen(pkgLen){}
}OPENAVL_STRUCT avlHeader_t;

typedef struct __avlData__ {
    avlHeader_t header;
    uint8_t eventUid;
    gpsData_t gpsData; // 14 bytes
    uint32_t flags;
    trackId_t trackId;
    uint32_t secuence_n;

    __avlData__()
        : header ( 0 ),
          eventUid ( 0 ),
          flags ( 0 ),
          secuence_n ( 0 )
    {}

    __avlData__ ( trackId_t& id, gpsData_t& gps, uint8_t ev_id, uint16_t pkgLen, uint32_t flags = 0 )
        : header ( pkgLen),
          eventUid ( ev_id ),
          gpsData ( gps ),
          flags ( flags ),
          trackId ( id ),
          secuence_n ( 0 )
    {}
} OPENAVL_STRUCT avlData_t;

}

