#ifndef OAVL_EV_EngineCutoff_H 
#define OAVL_EV_EngineCutoff_H
#include "Common/general_event.h"
#include "Avl_ids.h"

namespace OAVL{

    namespace Events{
        class EngineCutoff : public GeneralEvent{
        public:
            EngineCutoff(trackId_t& id, gpsData_t& gps, uint32_t flags = 0 ) : GeneralEvent(id, gps, OAVL_ENGINECUTOFF_EV, flags){
                CalculateCrc();
            }
        };
    }
}


#endif