#ifndef OAVL_EV_EngineStart_H 
#define OAVL_EV_EngineStart_H
#include "Common/general_event.h"
#include "Avl_ids.h"

namespace OAVL{

    namespace Events{
        class EngineStart : public GeneralEvent{
        public:
            EngineStart(trackId_t& id, gpsData_t& gps, uint32_t flags = 0 ) : GeneralEvent(id, gps, OAVL_ENGINESTART_EV, flags){
                CalculateCrc();
            }
        };
    }
}


#endif