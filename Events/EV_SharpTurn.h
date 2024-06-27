#ifndef OAVL_EV_SharpTurn_H 
#define OAVL_EV_SharpTurn_H
#include "Common/general_event.h"
#include "Avl_ids.h"

namespace OAVL{

    namespace Events{
        class SharpTurn : public GeneralEvent{
        public:
            SharpTurn(trackId_t& id, gpsData_t& gps, uint32_t flags = 0 ) : GeneralEvent(id, gps, OAVL_SHARPTURN_EV, flags){
                CalculateCrc();
            }
        };
    }
}


#endif