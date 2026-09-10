#pragma once
#include <types.h>

/// @brief Wrapper around the runtime's formatted print function.
/// @ingroup slib
class sPrintf {
public:
    /// @brief The signature of the function used to print formatted output.
    typedef int (*vprintfFunc)(const char *format, va_list *args);

    /// @brief Gets the function used to print formatted output.
    static vprintfFunc GetVPrintfFunc();
    /**
     * @brief Prints formatted output.
     *
     * @param format The format string.
     * @param args The arguments for the format string.
     * @return The number of characters printed.
     */
    static int vprintf(const char *format, va_list *args);
};
