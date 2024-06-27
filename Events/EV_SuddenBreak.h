#ifndef OAVL_EV_SuddenBreak_H 
#define OAVL_EV_SuddenBreak_H
#include "Common/general_event.h"
#include "Avl_ids.h"

namespace OAVL{

    namespace Events{
        class SuddenBreak : public GeneralEvent{
        public:
            SuddenBreak(trackId_t& id, gpsData_t& gps, uint32_t flags = 0 ) : GeneralEvent(id, gps, OAVL_SUDDENBREAK_EV, flags){
                CalculateCrc();
            }
        };
    }
}


#endif