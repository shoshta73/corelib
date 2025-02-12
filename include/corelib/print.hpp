#ifndef CORELIB_PRINT_HPP
#define CORELIB_PRINT_HPP 1

#include <format>
#include <print>
#include <utility>

namespace corelib {

    template <typename... Args>
    void print(::std::format_string<Args...> fmt, Args&&...args)
    {
        ::std::print(fmt, std::forward<Args>(args)...);
    }

    template <typename... Args>
    void println(::std::format_string<Args...> fmt, Args&&...args)
    {
        ::std::println(fmt, std::forward<Args>(args)...);
    }

} // namespace corelib

#endif /* CORELIB_PRINT_HPP */
