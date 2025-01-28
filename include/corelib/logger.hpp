#ifndef __CORELIB_LOGGER_HPP__
#define __CORELIB_LOGGER_HPP__ 1

#include <corelib/internal/internal.h>

#include <format>
#include <string_view>
#include <string>
#include <source_location>

#include <corelib/def.hpp>
#include <corelib/print.hpp>

namespace corelib {

namespace log {

    namespace _detail {

        enum class Level : u8
        {
            PRINT,
            TRACE,
            DEBUG,
            INFO,
            WARNING,
            ERROR,
            CRITICAL,
            FATAL = CRITICAL,
            NONE = u8_max
        };

        template <Level L, class... Args>
        struct Logger
        {
            constexpr Logger(::std::format_string<Args...> msg, Args &&...args, ::std::source_location loc = ::std::source_location::current())
            {
                if constexpr (L == Level::NONE)
                {
                    return;
                }

                auto lvl_str = "";
                if constexpr (L == Level::PRINT)
                {
                    lvl_str = "";
                }
                else if constexpr (L == Level::TRACE)
                {
                    lvl_str = "trace";
                }
                else if constexpr (L == Level::DEBUG)
                {
                    lvl_str = "debug";
                }
                else if constexpr (L == Level::INFO)
                {
                    lvl_str = "info";
                }
                else if constexpr (L == Level::WARNING)
                {
                    lvl_str = "warning";
                }
                else if constexpr (L == Level::ERROR)
                {
                    lvl_str = "error";
                }

                auto fmt_msg = ::std::format(msg, std::forward<Args>(args)...);
                ::corelib::println("[{}]({}:{} in {}): {}", lvl_str, loc.file_name(), loc.line(), loc.function_name(), fmt_msg);
            }
        };

        template <Level L = Level::NONE, class... Args>
        Logger(::std::format_string<Args...>, Args &&...) -> Logger<L, Args...>;

    } // namespace _detail

    template <class... Args>
    using print = log::_detail::Logger<_detail::Level::INFO, Args...>;

    template <class... Args>
    using trace = log::_detail::Logger<_detail::Level::TRACE, Args...>;

    template <class... Args>
    using debug = log::_detail::Logger<_detail::Level::DEBUG, Args...>;

    template <class... Args>
    using info = log::_detail::Logger<_detail::Level::INFO, Args...>;

    template <class... Args>
    using warning = log::_detail::Logger<_detail::Level::WARNING, Args...>;

    template <class... Args>
    using error = log::_detail::Logger<_detail::Level::ERROR, Args...>;

    template <class... Args>
    using critical = log::_detail::Logger<_detail::Level::CRITICAL, Args...>;

    template <class... Args>
    using fatal = log::_detail::Logger<_detail::Level::FATAL, Args...>;

    template <class... Args>
    using none = log::_detail::Logger<_detail::Level::NONE, Args...>;
}

} // namespace corelib::log

#endif // __CORELIB_LOGGER_HPP__
