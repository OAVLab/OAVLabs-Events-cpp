#ifndef OAVL_EV_SpeedStart_H 
#define OAVL_EV_SpeedStart_H
#include "Common/data_event.h"
#include "Avl_ids.h"



namespace OAVL{



    namespace Events{
        class SpeedStart : public DataEvent<uint16_t>{
        public:
            SpeedStart(trackId_t& id, gpsData_t& gps, uint16_t data, uint32_t flags = 0 ) : DataEvent(id, gps, OAVL_SPEEDSTART_EV, data, flags){
                CalculateCrc();
            }

        private:

        };
    }
}


#endif