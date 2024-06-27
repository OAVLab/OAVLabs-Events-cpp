#ifndef OAVL_EV_SpeedStop_H 
#define OAVL_EV_SpeedStop_H
#include "Common/data_event.h"
#include "Avl_ids.h"



namespace OAVL{



    namespace Events{
        class SpeedStop : public DataEvent<uint16_t>{
        public:
            SpeedStop(trackId_t& id, gpsData_t& gps, uint16_t data, uint32_t flags = 0 ) : DataEvent(id, gps, OAVL_SPEEDSTOP_EV, data, flags){
                CalculateCrc();
            }

        private:

        };
    }
}


#endif