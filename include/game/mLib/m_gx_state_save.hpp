#pragma once

#include <revolution/GX/GXAttr.h>

/// @brief Saves and restores a subset of GX hardware state.
/// @ingroup mlib
class GXStateSave_c {
public:
    GXStateSave_c(); ///< Constructs an empty state save (nothing saved yet).
    ~GXStateSave_c(); ///< Destroys the instance.

    /// @brief Saves the GX state selected by @p flags.
    /// @param flags Bitmask of which state to save; merged into any state already saved.
    void save(ulong flags);

    /// @brief Restores all previously saved GX state, then clears it.
    void restore();

private:
    u32 mFlags; ///< Bitmask of which fields are currently saved.
    GXVtxAttrFmtList mVtxAttrFmt[GX_VA_MAX_ATTR + 1]; ///< Saved vertex attribute formats.
    GXVtxDescList mVtxDesc[GX_VA_MAX_ATTR + 1]; ///< Saved vertex descriptors.
    f32 mProjection[7]; ///< Saved projection matrix (@p mProjection[0] is the GXProjectionType).
    f32 mViewport[6]; ///< Saved viewport (x, y, width, height, nearZ, farZ).
    u32 mScissor[4]; ///< Saved scissor rectangle (x, y, width, height).
    u32 mCullMode; ///< Saved cull mode.
    u8 mColorUpdate; ///< Saved color channel update flag.
    u8 mAlphaUpdate; ///< Saved alpha channel update flag.
    u8 mDither; ///< Saved dither flag.
};
