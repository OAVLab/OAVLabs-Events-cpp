#ifndef DATA_EVENT_H
#define DATA_EVENT_H

#include <cstring> // for std::memcpy
#include <stdexcept>

#include "avl_types.h"
#include "crc16.h"
#include "event_interface.h"

#define OPENAVL_EXTRA_DATA_MAX_LEN  OPENAVL_MAX_PKG_SIZE-((sizeof(AvlData)+sizeof(extraDataLen)+sizeof(crc))

namespace OAVL
{
template <typename T> class DataEvent : public IEvent
{
public:
    DataEvent ( trackId_t& id, gpsData_t& gps, uint8_t ev_id, uint32_t flags) : event ( id,gps,ev_id, flags )
    {
        if ( sizeof ( T ) > OPENAVL_MAX_PKG_SIZE )
            throw std::runtime_error ( "Size of extraData type is grater than allowed package size" );
    }

    DataEvent ( trackId_t& id, gpsData_t& gps, uint8_t ev_id, T extraData, uint32_t flags ) : event ( id,gps,ev_id, extraData, flags )
    {
        if ( sizeof ( T ) > OPENAVL_MAX_PKG_SIZE )
            throw std::runtime_error ( "Size of extraData type is grater than allowed package size" );
    }

    DataEvent(uint8_t* data): event() {
         std::memcpy(&event,data,  sizeof(Event));
    }


    virtual ~DataEvent() {}

public:

    typedef struct __Event__ {
        avlData_t avlData;
        T extraData;
        uint16_t crc16; //reserved memory. Crc16 is not necesaryly located here

        __Event__ () {}
        __Event__ ( trackId_t& id, gpsData_t& gps, uint8_t ev_id, uint32_t flags )
            : avlData ( id,gps, ev_id, sizeof ( Event ), flags), extraData (){}
        __Event__ ( trackId_t& id, gpsData_t& gps, uint8_t ev_id,  T& extraData, uint32_t flags )
            : avlData ( id,gps, ev_id, sizeof ( Event ), flags), extraData ( extraData ){}

    } OPENAVL_STRUCT Event;


protected:
    Event event;


public:
    uint16_t CalculateCrc()
    {
        uint16_t crc = Crc16::Calculate ( &this->event, sizeof ( Event ) - 2 );
        event.crc16 = crc;
        return crc;
    }
    uint8_t* GetBuff()
    {
        return reinterpret_cast<uint8_t *>(&event);
    }
    uint8_t Size()
    {
        return sizeof ( Event );       //add 2 bytes for CRC
    }
    void SetSecuence ( uint32_t secNum )
    {
        event.avlData.secuence_n = secNum;
    }

};

}

#endif

