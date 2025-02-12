#ifndef CORELIB_LOG_HPP
#define CORELIB_LOG_HPP 1

#include <cstddef>
#include <format>
#include <print>
#include <source_location>
#include <utility>

#include "templates.hpp"
#include "print.hpp"

namespace corelib { namespace log {

    namespace _detail {
        template <::std::size_t N>
        using StringLiteral = ::corelib::StringLiteral<N>;

        enum class LogLevel {
            Trace,
            Debug,
            Info,
            Warning,
            Warn = Warning,
            Error,
            Fatal,
            None,
        };

#if DEBUG
        constexpr auto min_level = LogLevel::Trace;
#else
        constexpr auto min_level = LogLevel::Warn;
#endif

        template <LogLevel L, typename... Args>
        struct LogImpl {
            LogImpl(::std::format_string<Args...> fmt, Args&&...args, const ::std::source_location& loc = ::std::source_location::current())
            {
                if constexpr (L == LogLevel::None || L < min_level)
                {
                    return;
                }

                const char *level;
                const char *color;
                constexpr const char *reset = "\033[0m";

                if constexpr (L == LogLevel::Trace)
                {
                    color = "\033[90m"; // Grey
                    level = "TRACE";
                }
                else if constexpr (L == LogLevel::Debug)
                {
                    color = "\033[36m"; // Cyan
                    level = "DEBUG";
                }
                else if constexpr (L == LogLevel::Info)
                {
                    color = "\033[32m"; // Green
                    level = "INFO ";
                }
                else if constexpr (L == LogLevel::Warning)
                {
                    color = "\033[33m"; // Yellow
                    level = "WARN ";
                }
                else if constexpr (L == LogLevel::Error)
                {
                    color = "\033[31m"; // Red
                    level = "ERROR";
                }
                else if constexpr (L == LogLevel::Fatal)
                {
                    color = "\033[97;41m"; // White text (97) on red background (41)
                    level = "FATAL";
                }

                corelib::println("{}{}:{} {} ( {}:{} in {} )", color, level, reset, ::std::format(fmt, ::std::forward<Args>(args)...), loc.file_name(), loc.line(), loc.function_name());
            }
        };

        template <LogLevel L = LogLevel::None, typename... Args>
        LogImpl(::std::format_string<Args...>, Args&&...) -> LogImpl<L, Args...>;

        template <StringLiteral Name, LogLevel L, typename... Args>
        struct NamedLogImpl {
            constexpr NamedLogImpl(::std::format_string<Args...> fmt, Args&&...args, const ::std::source_location& loc = ::std::source_location::current())
            {
                if constexpr (L == LogLevel::None || L < min_level)
                {
                    return;
                }

                const char *level;
                const char *color;
                constexpr const char *reset = "\033[0m";

                if constexpr (L == LogLevel::Trace)
                {
                    color = "\033[90m"; // Grey
                    level = "TRACE";
                }
                else if constexpr (L == LogLevel::Debug)
                {
                    color = "\033[36m"; // Cyan
                    level = "DEBUG";
                }
                else if constexpr (L == LogLevel::Info)
                {
                    color = "\033[32m"; // Green
                    level = "INFO";
                }
                else if constexpr (L == LogLevel::Warning)
                {
                    color = "\033[33m"; // Yellow
                    level = "WARN";
                }
                else if constexpr (L == LogLevel::Error)
                {
                    color = "\033[31m"; // Red
                    level = "ERROR";
                }
                else if constexpr (L == LogLevel::Fatal)
                {
                    color = "\033[97;41m"; // White text (97) on red background (41)
                    level = "FATAL";
                }

                corelib::println("{}{} [{}]:{} {} ( {}:{} in {} )", color, Name.value, level, reset, ::std::format(fmt, ::std::forward<Args>(args)...), loc.file_name(), loc.line(), loc.function_name());
            }
        };

        template <StringLiteral Name = "logger", LogLevel L = LogLevel::None, typename... Args>
        NamedLogImpl(::std::format_string<Args...>, Args&&...) -> NamedLogImpl<Name, L, Args...>;

    } // namespace _detail

    using namespace _detail;
    using Level = _detail::LogLevel;

    template <typename... Args>
    using trace = LogImpl<Level::Trace, Args...>;

    template <typename... Args>
    using debug = LogImpl<Level::Debug, Args...>;

    template <typename... Args>
    using info = LogImpl<Level::Info, Args...>;

    template <typename... Args>
    using warning = LogImpl<Level::Warning, Args...>;

    template <typename... Args>
    using warn = warning<Args...>;

    template <typename... Args>
    using error = LogImpl<Level::Error, Args...>;

    template <typename... Args>
    using fatal = LogImpl<Level::Fatal, Args...>;

    template <StringLiteral Name, typename... Args>
    using NamedTrace = NamedLogImpl<Name, Level::Trace, Args...>;

    template <StringLiteral Name, typename... Args>
    using NamedDebug = NamedLogImpl<Name, Level::Debug, Args...>;

    template <StringLiteral Name, typename... Args>
    using NamedInfo = NamedLogImpl<Name, Level::Info, Args...>;

    template <StringLiteral Name, typename... Args>
    using NamedWarning = NamedLogImpl<Name, Level::Warning, Args...>;

    template <StringLiteral Name, typename... Args>
    using NamedWarn = NamedWarning<Name, Args...>;

    template <StringLiteral Name, typename... Args>
    using NamedError = NamedLogImpl<Name, Level::Error, Args...>;

    template <StringLiteral Name, typename... Args>
    using NamedFatal = NamedLogImpl<Name, Level::Fatal, Args...>;

}} // namespace corelib::log

#endif /* CORELIB_LOG_HPP */
