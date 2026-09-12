#pragma once

#include <game/bases/d_actor.hpp>

class dEnCombo_c {
public:
    /// @unofficial
    enum ComboType_e {
        COMBO_NONE,
        COMBO_REGULAR,
        COMBO_SHORT
    };

    dEnCombo_c(ComboType_e type) : mType(type) {}

    int getComboScore(int);
    int getQuakeScore(int) const;
    int getDamageScore() const;
    void setScore(dActor_c *actor, int a, int b) const;

    static int calcPlStarCnt(dActor_c *actor);
    static int calcPlComboCnt(dActor_c *actor);
    static int calcPlFumiCnt(dActor_c *actor);

    ComboType_e mType;
};
