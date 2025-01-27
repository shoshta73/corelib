#ifndef __CORELIB_LOG_HPP__
#define __CORELIB_LOG_HPP__ 1

#include <corelib/internal/internal.h>

#include <format>
#include <source_location>
#include <string>
#include <print>

#include <corelib_config.h>

namespace corelib {

  namespace _detail {

    enum class LogLevel
    {
      NONE,
      DEBUG,
      INFO,
      WARN,
      ERROR,
      CRITICAL,
      FATAL,
    };

    template <LogLevel L, typename... Args>
    struct Logger
    {
      Logger(::std::format_string<Args...> msg, Args &&...args, ::std::source_location loc = ::std::source_location::current())
      {
        auto lvl_str = "";

        if constexpr (L == LogLevel::DEBUG)
        {
          lvl_str = "[ DEBUG ] ";
        }
        else if constexpr (L == LogLevel::INFO)
        {
          lvl_str = "[ INFO ] ";
        }
        else if constexpr (L == LogLevel::WARN)
        {
          lvl_str = "[ WARN ] ";
        }
        else if constexpr (L == LogLevel::ERROR)
        {
          lvl_str = "[ ERROR ] ";
        }
        else if constexpr (L == LogLevel::CRITICAL)
        {
          lvl_str = "[ CRITICAL ] ";
        }
        else if constexpr (L == LogLevel::FATAL)
        {
          lvl_str = "[ FATAL ] ";
        }

        auto location = ::std::format("{}:{} - {}:", loc.file_name(), loc.line(), loc.function_name());
        auto msg_str = ::std::format(msg, ::std::forward<Args>(args)...);
        ::std::println("{}{} {}", lvl_str, location, msg_str);
      }
    };

    template <LogLevel L = LogLevel::NONE, typename... Args>
    Logger(::std::format_string<Args...>, Args &&...) -> Logger<L, Args...>;

  } // namespace _detail

  namespace log {

    template <typename... Args>
    using print = ::corelib::_detail::Logger<::corelib::_detail::LogLevel::NONE, Args...>;

    template <typename... Args>
    using debug = ::corelib::_detail::Logger<::corelib::_detail::LogLevel::DEBUG, Args...>;

    template <typename... Args>
    using info = ::corelib::_detail::Logger<::corelib::_detail::LogLevel::INFO, Args...>;

    template <typename... Args>
    using warn = ::corelib::_detail::Logger<::corelib::_detail::LogLevel::WARN, Args...>;

    template <typename... Args>
    using error = ::corelib::_detail::Logger<::corelib::_detail::LogLevel::ERROR, Args...>;

    template <typename... Args>
    using critical = ::corelib::_detail::Logger<::corelib::_detail::LogLevel::CRITICAL, Args...>;

    template <typename... Args>
    using fatal = ::corelib::_detail::Logger<::corelib::_detail::LogLevel::FATAL, Args...>;

  } // namespace log

} // namespace corelib

#endif // __CORELIB_LOG_HPP__
