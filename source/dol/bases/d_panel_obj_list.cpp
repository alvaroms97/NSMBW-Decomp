#include <game/bases/d_panel_obj_list.hpp>

dPanelObjList_c::dPanelObjList_c()
    : mUnk00(0), mUnk04(0), mValue(0), mType(0), mChange(1), mPosX(0.0f), mPosY(0.0f),
      mScale(1.0f), mAngle(0), mParts(0) {}

dPanelObjList_c::~dPanelObjList_c() {}

u16 dPanelObjList_c::getValue() const {
    return mValue;
}

bool dPanelObjList_c::isChange() const {
    return mChange;
}

void dPanelObjList_c::setChange(bool change) {
    mChange = change;
}

f32 dPanelObjList_c::getPosX() const {
    return mPosX;
}

f32 dPanelObjList_c::getPosY() const {
    return mPosY;
}

f32 dPanelObjList_c::getPosZ() const {
    return mPosZ;
}

void dPanelObjList_c::setPosXY(f32 x, f32 y) {
    mPosX = x;
    mPosY = y;
}

void dPanelObjList_c::setPos(f32 x, f32 y, f32 z) {
    mPosX = x;
    mPosY = y;
    mPosZ = z;
}

int dPanelObjList_c::getType() const {
    return mType;
}

void dPanelObjList_c::setScaleFoot(f32 scale) {
    mType = 1;
    mScale = scale;
    mAngle = 0;
    mParts = 0;
}

void dPanelObjList_c::setScaleAngle(f32 scale, s16 angle) {
    mType = 2;
    mScale = scale;
    mAngle = angle;
    mParts = 0;
}

f32 dPanelObjList_c::getScale() const {
    int type = getType();
    f32 result = 1.0f;
    if ((u32)(type - 1) <= 1) {
        result = mScale;
    }
    return result;
}

f32 dPanelObjList_c::getAngleF() const {
    return (f32)getAngleS() * 9.58738019107841e-05f;
}

s16 dPanelObjList_c::getAngleS() const {
    int type = getType();
    s16 result = 0;
    if ((u32)(type - 2) <= 1) {
        result = mAngle;
    }
    return result;
}

u8 dPanelObjList_c::getParts() const {
    if (getType() == 3) {
        return mParts;
    }
    return 0;
}
