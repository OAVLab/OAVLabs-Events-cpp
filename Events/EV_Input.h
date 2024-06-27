#ifndef OAVL_EV_Input_H 
#define OAVL_EV_Input_H
#include "Common/data_event.h"
#include "Avl_ids.h"

#define OAVL_INPUT_MAX_ID 31
#define OAVL_INPUT_MAX_TIME 900 // up to 15 minutes/hours

namespace OAVL{

    typedef struct __IO__ {
        uint16_t id: 5; // up to 32 ids
        uint16_t state: 1; // 0 = off. 1 = on
        uint16_t time: 10; // time it was turned on/off
    
        __IO__() {}
        __IO__(uint8_t id, bool state, uint16_t time): id(id), state(state), time(time) {}
    } OPENAVL_STRUCT IO_t;


    namespace Events{
        class Input : public DataEvent<IO_t>{
        public:
            Input(trackId_t& id, gpsData_t& gps, IO_t data, uint32_t flags = 0 ) : DataEvent(id, gps, OAVL_INPUT_EV, data, flags){
                CalculateCrc();
            }
            Input(trackId_t& id, gpsData_t& gps, uint8_t inputId, bool state, uint16_t time, uint32_t flags = 0 ) : DataEvent(id, gps, OAVL_INPUT_EV, flags) {
                if (inputId > OAVL_INPUT_MAX_ID)
                    throw std::runtime_error("OAVL does not support input id greater than 31");

                if (time > OAVL_INPUT_MAX_TIME)
                    time = OAVL_INPUT_MAX_TIME;

                IO_t m_pkg(inputId, state, time);
                this->event.extraData = m_pkg;
                CalculateCrc();
            }

        private:

        };
    }
}


#endif