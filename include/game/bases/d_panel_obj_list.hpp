#pragma once
#include <types.h>

/// @brief A single entry of a world map panel object list, storing position, scale and angle.
/// @ingroup bases
class dPanelObjList_c {
public:
    dPanelObjList_c(); ///< Constructs an entry at the origin with default scale and no change flag.
    ~dPanelObjList_c(); ///< Destroys the entry.

    u16 getValue() const; ///< Returns the associated value.
    bool isChange() const; ///< Returns whether the entry has changed since last query.
    void setChange(bool change); ///< Sets whether the entry has changed since last query.
    f32 getPosX() const; ///< Returns the X position.
    f32 getPosY() const; ///< Returns the Y position.
    f32 getPosZ() const; ///< Returns the Z position.
    void setPosXY(f32 x, f32 y); ///< Sets the X and Y position.
    void setPos(f32 x, f32 y, f32 z); ///< Sets the X, Y and Z position.
    int getType() const; ///< Returns the entry's type. @unofficial Exact meaning of each value unknown.

    /// @brief Sets the entry to the "foot" type with the given scale.
    /// @unofficial Named after the parameter usage; the exact meaning of this type is unconfirmed.
    void setScaleFoot(f32 scale);

    /// @brief Sets the entry to the scale+angle type with the given scale and angle.
    void setScaleAngle(f32 scale, s16 angle);

    /// @brief Returns the scale value, or a default of @p 1.0f if the type does not use scale.
    f32 getScale() const;

    /// @brief Returns @ref getAngleS converted to radians.
    f32 getAngleF() const;

    /// @brief Returns the angle value, or @p 0 if the type does not use angle.
    s16 getAngleS() const;

    /// @brief Returns the parts index, or @p 0 if the type does not use parts.
    u8 getParts() const;

private:
    u32 mUnk00; ///< @unofficial Unknown. Never read by any decompiled code so far.
    u32 mUnk04; ///< @unofficial Unknown. Never read by any decompiled code so far.
    u16 mValue; ///< The associated value.
    u8 mType; ///< @unofficial The entry's type; controls which of mScale/mAngle/mParts are valid.
    u8 mChange; ///< Whether the entry has changed since last query.
    f32 mPosX; ///< The X position.
    f32 mPosY; ///< The Y position.
    f32 mPosZ; ///< The Z position.
    f32 mScale; ///< The scale value, valid when mType is 1 or 2.
    s16 mAngle; ///< The angle value, valid when mType is 2 or 3.
    u8 mParts; ///< The parts index, valid when mType is 3.
};
