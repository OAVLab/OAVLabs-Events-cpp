#ifndef OAVL_EV_Handshake_H 
#define OAVL_EV_Handshake_H
#include "Common/data_event.h"
#include "Avl_ids.h"

#define OAVL_HANDSHAKE_IMEI_LEN 15
#define OAVL_HANDSHAKE_SN_LEN 20


namespace OAVL{

    typedef struct __version__{
        uint8_t major;
        uint8_t minor;
        uint8_t release;
    }OPENAVL_STRUCT version_st;

    typedef struct __handshake__{
        version_st oavlVersion;
        version_st fwVersion;
        char IMEI[OAVL_HANDSHAKE_IMEI_LEN];
        char serialNumber[OAVL_HANDSHAKE_SN_LEN];

        __handshake__(){}
        __handshake__(version_st& oavlVer, version_st& fwVer)
            : oavlVersion(oavlVer), fwVersion(fwVer){
                std::memset(IMEI, 0, OAVL_HANDSHAKE_IMEI_LEN);
                std::memset(serialNumber, 0, OAVL_HANDSHAKE_SN_LEN);
        }
    }OPENAVL_STRUCT handshake_t;


    namespace Events{
        class Handshake : public DataEvent<handshake_t>{
        public:
            Handshake(trackId_t& id, gpsData_t& gps, handshake_t data, uint32_t flags = 0 ) : DataEvent(id, gps, OAVL_HANDSHAKE_EV, data, flags){
                CalculateCrc();
            }
            Handshake (trackId_t& id, gpsData_t& gps,version_st& fwVersion, std::string imei, std::string sn, uint32_t flags = 0) : DataEvent<handshake_t> ( id, gps, OAVL_HANDSHAKE_EV, flags ) {
                if(imei.length() > OAVL_HANDSHAKE_IMEI_LEN)
                    throw std::runtime_error("IMEI length can not be more than 15 digits. Handshake package can not be created");

                if(sn.length() > OAVL_HANDSHAKE_SN_LEN)
                    throw std::runtime_error("Serial number is too long. Handshake package can not be created");


                version_st libVer = Handshake::oavlVersion();
                handshake_t m_pkg( libVer, fwVersion );    std::memcpy(m_pkg.IMEI, imei.c_str(), imei.length());
                std::memcpy(m_pkg.serialNumber, sn.c_str(), sn.length());
                this->event.extraData=m_pkg;
                CalculateCrc();
            }

        private:
            static version_st oavlVersion(){
                const version_st oavlVersion = {OAVL_VERSION};
                return oavlVersion;
            };

        };
    }
}


#endif