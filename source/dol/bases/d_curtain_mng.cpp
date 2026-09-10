#include <game/bases/d_curtain_mng.hpp>

void dCurtainMng_c::CurtainInfoAllClear() {
    for (int i = 0; i < 4; i++) {
        CurtainInfo_c *info = m_curtainInfo[i];

        info[0].field_0x0 = 0xFFFF;
        info[0].field_0x4[0] = 0.0f;
        info[0].field_0x4[1] = 0.0f;
        info[0].field_0x4[2] = 0.0f;
        info[0].field_0x4[3] = 0.0f;
        info[0].field_0x4[4] = 0.0f;
        info[0].field_0x4[5] = 0.0f;
        info[0].field_0x4[6] = 0.0f;
        info[0].field_0x4[7] = 0.0f;

        info[1].field_0x0 = 0xFFFF;
        info[1].field_0x4[0] = 0.0f;
        info[1].field_0x4[1] = 0.0f;
        info[1].field_0x4[2] = 0.0f;
        info[1].field_0x4[3] = 0.0f;
        info[1].field_0x4[4] = 0.0f;
        info[1].field_0x4[5] = 0.0f;
        info[1].field_0x4[6] = 0.0f;
        info[1].field_0x4[7] = 0.0f;

        info[2].field_0x0 = 0xFFFF;
        info[2].field_0x4[0] = 0.0f;
        info[2].field_0x4[1] = 0.0f;
        info[2].field_0x4[2] = 0.0f;
        info[2].field_0x4[3] = 0.0f;
        info[2].field_0x4[4] = 0.0f;
        info[2].field_0x4[5] = 0.0f;
        info[2].field_0x4[6] = 0.0f;
        info[2].field_0x4[7] = 0.0f;

        info[3].field_0x0 = 0xFFFF;
        info[3].field_0x4[0] = 0.0f;
        info[3].field_0x4[1] = 0.0f;
        info[3].field_0x4[2] = 0.0f;
        info[3].field_0x4[3] = 0.0f;
        info[3].field_0x4[4] = 0.0f;
        info[3].field_0x4[5] = 0.0f;
        info[3].field_0x4[6] = 0.0f;
        info[3].field_0x4[7] = 0.0f;
    }
}
