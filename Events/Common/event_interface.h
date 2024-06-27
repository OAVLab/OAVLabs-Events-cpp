#ifndef EVENT_INTERFACE_H
#define EVENT_INTERFACE_H

#include <inttypes.h>

class IEvent
{
public:
    virtual ~IEvent() {};
    virtual uint16_t CalculateCrc() = 0;
    virtual uint8_t* GetBuff() = 0;
    virtual uint8_t Size() = 0;
    virtual void SetSecuence ( uint32_t secNum ) = 0;
};

#endif
