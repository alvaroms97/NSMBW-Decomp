#include <game/sLib/s_printf.hpp>
#include <revolution/OS/OSError.h>

// TENTATIVE NAME (dtk auto-generated): the .sdata function pointer at 0x80429700.
extern sPrintf::vprintfFunc lbl_80429700;

sPrintf::vprintfFunc sPrintf::GetVPrintfFunc() {
    return lbl_80429700;
}

int sPrintf::vprintf(const char *format, va_list *args) {
    return GetVPrintfFunc()(format, args);
}

extern "C" void OSReport(const char *msg, ...) {
    va_list list;
    va_start(list, msg);
    OSVReport(msg, &list);
    va_end(list);
}

extern "C" void OSVReport(const char *msg, va_list *list) {
    sPrintf::vprintf(msg, list);
}
