#pragma once

#include <types.h>

namespace EGG {

/// @brief An entry in a MsgRes's message table.
/// @unofficial Only the fields actually read by NSMBW-Decomp so far are named; the rest of the layout is unknown.
struct MsgEntry {
    u8 unk_00[4]; ///< @unofficial Unknown.
    u16 scale; ///< at 0x4
    u8 font; ///< at 0x6
};

class MsgRes {
public:
    MsgRes(const void *p);
    ~MsgRes();

    wchar_t *getMsg(ulong messageGroup, ulong messageID);
    MsgEntry *getMsgEntry(ulong messageGroup, ulong messageID);

private:
    u8 unk_00[0x1c]; ///< @unofficial Unknown. Size confirmed by MsgRes_c's own vtable pointer landing at 0x1c.
};

} // namespace EGG
