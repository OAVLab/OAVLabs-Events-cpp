#ifndef OAVL_EV_StoppedStart_H 
#define OAVL_EV_StoppedStart_H
#include "Common/general_event.h"
#include "Avl_ids.h"

namespace OAVL{

    namespace Events{
        class StoppedStart : public GeneralEvent{
        public:
            StoppedStart(trackId_t& id, gpsData_t& gps, uint32_t flags = 0 ) : GeneralEvent(id, gps, OAVL_STOPPEDSTART_EV, flags){
                CalculateCrc();
            }
        };
    }
}


#endif