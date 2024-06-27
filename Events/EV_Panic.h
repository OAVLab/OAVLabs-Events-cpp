#ifndef OAVL_EV_Panic_H 
#define OAVL_EV_Panic_H
#include "Common/general_event.h"
#include "Avl_ids.h"

namespace OAVL{

    namespace Events{
        class Panic : public GeneralEvent{
        public:
            Panic(trackId_t& id, gpsData_t& gps, uint32_t flags = 0 ) : GeneralEvent(id, gps, OAVL_PANIC_EV, flags){
                CalculateCrc();
            }
        };
    }
}


#endif