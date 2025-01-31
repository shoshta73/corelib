#ifndef __CORELIB_PRINT_HPP__
#define __CORELIB_PRINT_HPP__ 1

#include <corelib/internal/internal.hpp>

#if CORELIB_HAS_CXX23
#include <format>
#include <print>
#else
#include <format>
#include <iostream>
#endif

namespace corelib {

    template <typename... Args>
    constexpr void
    println(std::format_string<Args...> msg, Args &&...args)
    {
#if CORELIB_HAS_CXX23
        std::println("{}", std::format(msg, std::forward<Args>(args)...));
#else
        std::cout << std::format(msg, std::forward<Args>(args)...) << '\n';
#endif
    }

    template <typename... Args>
    constexpr void
    print(std::format_string<Args...> msg, Args &&...args)
    {
#if CORELIB_HAS_CXX23
        std::print("{}", std::format(msg, std::forward<Args>(args)...));
#else
        std::cout << std::format(msg, std::forward<Args>(args)...);
#endif
    }

} // namespace corelib

#endif // __CORELIB_PRINT_HPP__
