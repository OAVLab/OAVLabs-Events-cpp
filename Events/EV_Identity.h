#ifndef OAVL_EV_Identity_H 
#define OAVL_EV_Identity_H
#include "Common/data_event.h"
#include "Avl_ids.h"



namespace OAVL{



    namespace Events{
        class Identity : public DataEvent<trackId_t>{
        public:
            Identity(trackId_t& id, gpsData_t& gps, trackId_t data, uint32_t flags = 0 ) : DataEvent(id, gps, OAVL_IDENTITY_EV, data, flags){
                CalculateCrc();
            }

        private:

        };
    }
}


#endif