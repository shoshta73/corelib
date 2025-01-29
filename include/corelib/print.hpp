#ifndef __CORELIB_LOG_HPP__
#define __CORELIB_LOG_HPP__ 1

#include <corelib/internal/internal.h>

#include <format>
#include <print>

namespace corelib {

    template <typename... Args>
    constexpr void
    println(std::format_string<Args...> msg, Args &&...args)
    {
        std::println("{}", std::format(msg, std::forward<Args>(args)...));
    }

    template <typename... Args>
    constexpr void
    print(std::format_string<Args...> msg, Args &&...args)
    {
        std::print("{}", std::format(msg, std::forward<Args>(args)...));
    }

} // namespace corelib

#endif // __CORELIB_LOG_HPP__
