#ifndef __CORELIB_LOG_HPP__
#define __CORELIB_LOG_HPP__ 1

#include <corelib/internal/internal.h>

#include <format>
#include <print>

namespace corelib {

  namespace _detail {

    template <typename... Args>
    struct Printer
    {
      constexpr Printer(::std::format_string<Args...> msg, Args &&...args)
      {
        ::std::println("{}", ::std::format(msg, ::std::forward<Args>(args)...));
      }
    };

    template <typename... Args>
    Printer(::std::format_string<Args...>, Args &&...) -> Printer<Args...>;

  } // namespace _detail

  template <typename... Args>
  using print = ::corelib::_detail::Printer<Args...>;

} // namespace corelib

#endif // __CORELIB_LOG_HPP__
