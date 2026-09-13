#pragma once

#include <types.h>

#include <revolution/GX.h>

namespace EGG {

namespace StateGX {
    void initialize(unsigned short, unsigned short, GXColor, GXPixelFmt);
    void resetGXCache();
    void GXSetProjectionv_(const f32 *param); ///< @unofficial
    void GXSetViewport_(f32 x, f32 y, f32 width, f32 height, f32 nearZ, f32 farZ); ///< @unofficial
    void GXSetScissor_(ulong x, ulong y, ulong w, ulong h); ///< @unofficial
    void GXGetScissor_(ulong *x, ulong *y, ulong *w, ulong *h); ///< @unofficial
    void GXSetColorUpdate_(bool enable); ///< @unofficial
    void GXSetAlphaUpdate_(bool enable); ///< @unofficial
    void GXSetDither_(bool enable); ///< @unofficial
}

} // namespace EGG
