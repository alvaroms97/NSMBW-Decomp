#pragma once
#include <types.h>

class dCurtainMng_c {
public:
    void CurtainInfoAllClear();

private:
    struct CurtainInfo_c {
        u16 field_0x0;
        float field_0x4[8];
    };

    CurtainInfo_c m_curtainInfo[4][4];
};
