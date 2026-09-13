#include <game/mLib/m_gx_state_save.hpp>
#include <revolution/GX.h>
#include <egg/gfxe/eggStateGX.h>

// Bitfield flags for saved state
#define FLAG_VTXDESC      0x1
#define FLAG_VTXATTRFMT   0x2
#define FLAG_PROJECTION   0x4
#define FLAG_VIEWPORT     0x8
#define FLAG_CULLMODE     0x10
#define FLAG_SCISSOR      0x20
#define FLAG_COLORUPDATE  0x40
#define FLAG_ALPHAUPDATE  0x80
#define FLAG_DITHER       0x100

// Cache of GX state used by EGG::StateGX (unofficial)
// Stores ColorUpdate at offset 0xC, AlphaUpdate at 0xD, Dither at 0xE
extern u8 s_cacheGX__Q23EGG7StateGX[];

GXStateSave_c::GXStateSave_c() : mFlags(0) {
}

GXStateSave_c::~GXStateSave_c() {
}

void GXStateSave_c::save(ulong flags) {
    if (flags & FLAG_VTXDESC) {
        GXGetVtxDescv(mVtxDesc);
    }
    if (flags & FLAG_VTXATTRFMT) {
        GXGetVtxAttrFmtv(GX_VTXFMT0, mVtxAttrFmt);
    }
    if (flags & FLAG_PROJECTION) {
        GXGetProjectionv(mProjection);
    }
    if (flags & FLAG_VIEWPORT) {
        GXGetViewportv(mViewport);
    }
    if (flags & FLAG_CULLMODE) {
        GXGetCullMode((GXCullMode*)&mCullMode);
    }
    if (flags & FLAG_SCISSOR) {
        EGG::StateGX::GXGetScissor_((ulong *)&mScissor[0], (ulong *)&mScissor[1],
                                     (ulong *)&mScissor[2], (ulong *)&mScissor[3]);
    }
    if (flags & FLAG_COLORUPDATE) {
        mColorUpdate = s_cacheGX__Q23EGG7StateGX[0xC];
    }
    if (flags & FLAG_ALPHAUPDATE) {
        mAlphaUpdate = s_cacheGX__Q23EGG7StateGX[0xD];
    }
    if (flags & FLAG_DITHER) {
        mDither = s_cacheGX__Q23EGG7StateGX[0xE];
    }
    mFlags |= flags;
}

void GXStateSave_c::restore() {
    if (mFlags & FLAG_VTXDESC) {
        GXSetVtxDescv(mVtxDesc);
    }
    if (mFlags & FLAG_VTXATTRFMT) {
        GXSetVtxAttrFmtv(GX_VTXFMT0, mVtxAttrFmt);
    }
    if (mFlags & FLAG_CULLMODE) {
        GXSetCullMode((GXCullMode)mCullMode);
    }
    if (mFlags & FLAG_PROJECTION) {
        EGG::StateGX::GXSetProjectionv_(mProjection);
    }
    if (mFlags & FLAG_VIEWPORT) {
        EGG::StateGX::GXSetViewport_(mViewport[0], mViewport[1], mViewport[2], mViewport[3],
                                     mViewport[4], mViewport[5]);
    }
    if (mFlags & FLAG_SCISSOR) {
        EGG::StateGX::GXSetScissor_(mScissor[0], mScissor[1], mScissor[2], mScissor[3]);
    }
    if (mFlags & FLAG_COLORUPDATE) {
        EGG::StateGX::GXSetColorUpdate_(mColorUpdate);
    }
    if (mFlags & FLAG_ALPHAUPDATE) {
        EGG::StateGX::GXSetAlphaUpdate_(mAlphaUpdate);
    }
    if (mFlags & FLAG_DITHER) {
        EGG::StateGX::GXSetDither_(mDither);
    }
    mFlags = 0;
}
