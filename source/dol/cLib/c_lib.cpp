#include <game/cLib/c_lib.hpp>
#include <lib/egg/math/eggMath.h>
#include <lib/revolution/MTX/vec.h>
#include <math.h>

inline bool isZero(float val) {
    return (std::fabs(val) < FLT_EPSILON);
}

inline float calcDistance(const mVec3_c &a, const mVec3_c &b) {
    float dx = a.x - b.x;
    float dy = a.y - b.y;
    float dz = a.z - b.z;
    return EGG::Mathf::sqrt(dx * dx + dy * dy + dz * dz);
}

namespace cLib {

float addCalcPos(mVec3_c *pos, const mVec3_c &target, float ratio, float maxSpeed, float minSpeed) {
    if (*pos != target) {
        mVec3_c diff;
        diff = *pos - target;
        float mag = PSVECMag(diff);
        if (mag < minSpeed) {
            *pos = target;
        } else {
            diff *= ratio;
            float stepMag = mag * ratio;
            if (!isZero(stepMag)) {
                if (stepMag > maxSpeed) {
                    diff *= maxSpeed / stepMag;
                } else if (stepMag < minSpeed) {
                    diff *= minSpeed / stepMag;
                }
                *pos -= diff;
            } else {
                *pos = target;
            }
        }
    }

    return calcDistance(*pos, target);
}

bool chasePos(mVec3_c *pos, const mVec3_c &target, float speed) {
    if (speed) {
        mVec3_c diff = *pos - target;
        float mag = PSVECMag(diff);
        if (isZero(mag) || mag <= speed) {
            *pos = target;
            return true;
        }
        *pos -= (speed / mag) * diff;
    } else if (*pos == target) {
        return true;
    }
    return false;
}

s16 targetAngleY(const mVec3_c &vec1, const mVec3_c &vec2) {
    return cM::atan2s(vec2.x - vec1.x, vec2.z - vec1.z);
}

s16 targetAngleX(const mVec3_c &vec1, const mVec3_c &vec2) {
    mVec3_c diff = vec2 - vec1;
    return cM::atan2s(diff.y, EGG::Mathf::sqrt(diff.x * diff.x + diff.z * diff.z));
}

} // namespace cLib
