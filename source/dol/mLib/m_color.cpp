#include <game/mLib/m_color.hpp>

void mColor::lerp(const GXColor &from, const GXColor &to, float t) {
    float s = 1.0f - t;
    r = from.r * s + to.r * t;
    g = from.g * s + to.g * t;
    b = from.b * s + to.b * t;
    a = from.a * s + to.a * t;
}
