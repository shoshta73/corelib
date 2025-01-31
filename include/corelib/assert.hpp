#ifndef __CORELIB_ASSERT_HPP__
#define __CORELIB_ASSERT_HPP__ 1

#include <corelib/internal/internal.hpp>

#include <cstdlib>
#include <format>
#include <source_location>
#include <print>

namespace corelib {

    namespace _detail {

        template <class... Args>
        struct Assert
        {
            Assert(::std::source_location loc = ::std::source_location::current())
                : Assert(false, loc)
            {
            }

            Assert(bool cond, ::std::source_location loc = ::std::source_location::current())
            {
                if (!cond)
                {
                    ::std::println("Assertion failed: {}:{} in {}", loc.file_name(), loc.line(), loc.function_name());
                    ::std::abort();
                }
            }

            Assert(::std::format_string<Args...> msg, Args &&...args, ::std::source_location loc = ::std::source_location::current())
                : Assert(false, msg, args..., loc)
            {
            }

            Assert(bool cond, ::std::format_string<Args...> msg, Args &&...args, ::std::source_location loc = ::std::source_location::current())
            {
                if (!cond)
                {
                    auto location = ::std::format("{}:{} in {}", loc.file_name(), loc.line(), loc.function_name());
                    ::std::println("Assertion failed: {}: {}", location, ::std::format(msg, ::std::forward<Args>(args)...));

                    ::std::abort();
                }
            }
        };

        template <class... Args>
        Assert(bool, ::std::format_string<Args...>, Args &&...) -> Assert<Args...>;

        template <class... Args>
        Assert(::std::format_string<Args...>, Args &&...) -> Assert<Args...>;

    } // namespace _detail

    template <class... Args>
    using assert = _detail::Assert<Args...>;

} // namespace corelib

#endif // __CORELIB_ASSERT_HPP__
