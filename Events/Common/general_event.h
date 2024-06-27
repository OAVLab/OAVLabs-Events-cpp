#ifndef GENERALEVENT_H
#define GENERALEVENT_H

#include <cstring>

#include "avl_types.h"
#include "event_interface.h"
#include "crc16.h"

namespace OAVL
{

class GeneralEvent : public IEvent
{
public:
    GeneralEvent ( avlData_t& data ) : event ( data ) {}
    GeneralEvent ( trackId_t& id, gpsData_t& gps, uint8_t ev_id, uint32_t flags = 0 ) : event ( id,gps,ev_id, flags ) {}
    GeneralEvent ( uint8_t* data ) {
        std::memcpy(&event,data,  sizeof(Event));
    }
    virtual ~GeneralEvent() {};



public:
    typedef struct __Event__ {
        avlData_t avlData;
        uint16_t crc16;

        __Event__ (){}
        __Event__ ( avlData_t& avlData ) : avlData ( avlData ) {}
        __Event__ ( trackId_t& id, gpsData_t& gps, uint8_t ev_id, uint32_t flags ) : avlData ( id, gps, ev_id, flags, sizeof(__Event__)) {} //2 bytes for the crc
    } OPENAVL_STRUCT Event;



private:
    Event event;

public:
    uint16_t CalculateCrc()
    {
        event.crc16 = Crc16::Calculate ( &this->event.avlData, sizeof ( avlData_t ) );
        return event.crc16;
    }
    uint8_t* GetBuff()
    {
        return reinterpret_cast<uint8_t*>(&event);
    }
    uint8_t Size()
    {
        return sizeof ( Event );
    }
    void SetSecuence ( uint32_t secNum )
    {
        event.avlData.secuence_n = secNum;
    }

};

}
#endif // GENERALEVENT_H

