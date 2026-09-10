#include <game/sLib/s_crc.hpp>

// TENTATIVE NAME (dtk auto-generated): unresolved CRC32 calculation routine.
extern "C" u32 OSCalcCRC32(const void *data, unsigned long size); ///< @unofficial

u32 sCrc::calcCRC32(const void *data, unsigned long size) {
    return OSCalcCRC32(data, size);
}
