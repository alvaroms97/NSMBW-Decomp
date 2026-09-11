#pragma once

#include <types.h>
#include <egg/core/eggHeap.h>
#include <egg/core/eggMsgRes.h>
#include <game/bases/d_dvd.hpp>

class MsgRes_c : public EGG::MsgRes {
public:
    MsgRes_c(const void *p, EGG::Heap *heap);
    virtual ~MsgRes_c(); ///< Destroys the MsgRes_c instance.

    u8 getFont(ulong messageGroup, ulong messageID);
    u16 getScale(ulong messageGroup, ulong messageID);
};

class dMessage_c {
public:
    dMessage_c();
    ~dMessage_c();

    static bool create(EGG::Heap *heap);
    static wchar_t *getMsg(ulong messageGroup, ulong messageID);
    static MsgRes_c *getMesRes();
    static void changetoFullSize(wchar_t *str);

private:
    void buildMsgRes(EGG::Heap *heap);

    dDvd::loader_c mLoader;
    void *mpFileData;
    MsgRes_c *mpMsgRes;
};
