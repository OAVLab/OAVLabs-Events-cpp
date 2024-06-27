#ifndef OAVL_EV_Position_H 
#define OAVL_EV_Position_H
#include "Common/general_event.h"
#include "Avl_ids.h"

namespace OAVL{

    namespace Events{
        class Position : public GeneralEvent{
        public:
            Position(trackId_t& id, gpsData_t& gps, uint32_t flags = 0 ) : GeneralEvent(id, gps, OAVL_POSITION_EV, flags){
                CalculateCrc();
            }
        };
    }
}


#endif