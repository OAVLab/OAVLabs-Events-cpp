#ifndef OAVL_EV_StoppedEnd_H 
#define OAVL_EV_StoppedEnd_H
#include "Common/data_event.h"
#include "Avl_ids.h"



namespace OAVL{



    namespace Events{
        class StoppedEnd : public DataEvent<uint16_t>{
        public:
            StoppedEnd(trackId_t& id, gpsData_t& gps, uint16_t data, uint32_t flags = 0 ) : DataEvent(id, gps, OAVL_STOPPEDEND_EV, data, flags){
                CalculateCrc();
            }

        private:

        };
    }
}


#endif