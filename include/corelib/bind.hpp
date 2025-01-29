#ifndef __CORELIB_BINDER_HPP__
#define __CORELIB_BINDER_HPP__ 1

#include <corelib/internal/internal.h>

#include <functional>
#include <utility>
#include <type_traits>

namespace corelib {

    template <typename T, typename... Args>
    struct Bind
    {
        Bind(::std::function<T(Args...)> callback)
            : callback_(::std::move(callback))
        {
        }

        ::std::function<T(Args...)>
        operator()()
        {
            return callback_;
        }

    private:
        ::std::function<T(Args...)> callback_;
    };

} // namespace corelib

#endif
