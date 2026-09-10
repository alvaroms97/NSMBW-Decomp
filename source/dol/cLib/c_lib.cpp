#include <game/cLib/c_lib.hpp>
#include <lib/egg/math/eggMath.h>

namespace cLib {

s16 targetAngleY(const mVec3_c &vec1, const mVec3_c &vec2) {
    return cM::atan2s(vec2.x - vec1.x, vec2.z - vec1.z);
}

s16 targetAngleX(const mVec3_c &vec1, const mVec3_c &vec2) {
    mVec3_c diff = vec2 - vec1;
    return cM::atan2s(diff.y, EGG::Mathf::sqrt(diff.x * diff.x + diff.z * diff.z));
}

} // namespace cLib
