#include <game/bases/d_message.hpp>
#include <game/bases/d_game_com.hpp>
#include <egg/core/eggArchive.h>
#include <wchar.h>

static dMessage_c l_dMessage_obj;

dMessage_c::dMessage_c() {
    mpFileData = nullptr;
    mpMsgRes = nullptr;
}

dMessage_c::~dMessage_c() {
    delete mpMsgRes;
}

bool dMessage_c::create(EGG::Heap *heap) {
    if (l_dMessage_obj.mpFileData == nullptr) {
        char path[104];
        dGameCom::AreaLanguageFolder("Message/Message.arc", path);

        void *buffer = l_dMessage_obj.mLoader.request(path, 0, heap);
        if (buffer == nullptr) {
            return false;
        }

        EGG::Archive *archive = EGG::Archive::mount(buffer, heap, 4);

        EGG::Archive::FileInfo fileInfo;
        l_dMessage_obj.mpFileData = archive->getFile("wii_mj2d.bmg", &fileInfo);

        l_dMessage_obj.buildMsgRes(heap);
    }

    return true;
}

void dMessage_c::buildMsgRes(EGG::Heap *heap) {
    mpMsgRes = new (heap, 4) MsgRes_c(mpFileData, nullptr);
}

wchar_t *dMessage_c::getMsg(ulong messageGroup, ulong messageID) {
    return l_dMessage_obj.mpMsgRes->getMsg(messageGroup, messageID);
}

MsgRes_c *dMessage_c::getMesRes() {
    return l_dMessage_obj.mpMsgRes;
}

/// [TENTATIVE: unofficial name, real symbol not cracked]
/// Writes @p num into @p dst as @p digitCount decimal digits, replacing
/// suppressed leading zeros with spaces. At most @p writeLimit characters are
/// written, followed by a null terminator.
void numToWideStr(s32 num, wchar_t *dst, u32 writeLimit, s32 digitCount, s32 suppressLeadingZero) {
    u32 count = 0;
    s32 digitPos = digitCount - 1;
    s32 suppress = (suppressLeadingZero == 1);

    while (digitPos >= 0) {
        s32 pow10 = 1;
        for (s32 exp = 0; exp < digitPos; exp++) {
            pow10 *= 10;
        }

        s32 digit = (num % (pow10 * 10)) / pow10;

        if (digit == 0 && suppress != 0 && digitPos != 0) {
            dst[count] = 0x0020;
        } else {
            dst[count] = (wchar_t)(digit + '0');
            suppress = 0;
        }

        count++;
        digitPos--;
        if (writeLimit <= count) {
            break;
        }
    }

    dst[count] = 0;
}

/// [TENTATIVE: unofficial name, real symbol not cracked]
/// Same as ::numToWideStr, but converts the result to full-width characters.
void formatNumber(s32 num, wchar_t *dst, u32 writeLimit, s32 digitCount, s32 suppressLeadingZero) {
    numToWideStr(num, dst, writeLimit, digitCount, suppressLeadingZero);
    dMessage_c::changetoFullSize(dst);
}

void dMessage_c::changetoFullSize(wchar_t *str) {
    ulong len = wcslen(str);
    for (ulong i = 0; i < len; i++) {
        if (str[i] == 0x0020) {
            str[i] = 0x3000;
        } else if (str[i] >= 0x0021 && str[i] <= 0x007E) {
            str[i] = str[i] + 0xFEE0;
        }
    }
}
