#ifndef OAVL_EV_Synchronize_H 
#define OAVL_EV_Synchronize_H
#include "Common/data_event.h"
#include "Avl_ids.h"



namespace OAVL{



    namespace Events{
        class Synchronize : public DataEvent<uint32_t>{
        public:
            Synchronize(trackId_t& id, gpsData_t& gps, uint32_t data, uint32_t flags = 0 ) : DataEvent(id, gps, OAVL_SYNCHRONIZE_EV, data, flags){
                CalculateCrc();
            }

        private:

        };
    }
}


#endif