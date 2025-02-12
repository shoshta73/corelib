#ifndef CORELIB_TEMPLATES_HPP
#define CORELIB_TEMPLATES_HPP 1

#include <algorithm>
#include <cstddef>

namespace corelib {

    template <::std::size_t N>
    struct StringLiteral {
        constexpr StringLiteral(const char (&str)[N])
        {
            std::copy_n(str, N, value);
        }
        char value[N];
    };

} // namespace corelib

#endif /* CORELIB_TEMPLATES_HPP */
