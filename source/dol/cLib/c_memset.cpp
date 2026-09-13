#include <game/cLib/c_lib.hpp>
#include <MSL/cstring>

namespace cLib {

void memSet(void *dst, int val, ulong size) {
    std::memset(dst, val, size);
}

} // namespace cLib
