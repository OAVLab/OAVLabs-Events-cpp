#ifndef OAVL_EV_SuddenAcceleration_H 
#define OAVL_EV_SuddenAcceleration_H
#include "Common/general_event.h"
#include "Avl_ids.h"

namespace OAVL{

    namespace Events{
        class SuddenAcceleration : public GeneralEvent{
        public:
            SuddenAcceleration(trackId_t& id, gpsData_t& gps, uint32_t flags = 0 ) : GeneralEvent(id, gps, OAVL_SUDDENACCELERATION_EV, flags){
                CalculateCrc();
            }
        };
    }
}


#endif