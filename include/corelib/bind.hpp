#ifndef __CORELIB_BINDER_HPP__
#define __CORELIB_BINDER_HPP__ 1

#include <corelib/internal/internal.h>

#include <functional>
#include <utility>

namespace corelib {

  template <typename T, typename... Args>
  struct Bind
  {
    using CallbackType = std::function<T(Args...)>;

    Bind(CallbackType callback)
        : callback_(std::move(callback))
    {
    }

    CallbackType operator()()
    {
      return callback_;
    }

  private:
    CallbackType callback_;
  };

} // namespace corelib

#endif
