#ifndef __CORELIB_MEMORY_HPP__
#define __CORELIB_MEMORY_HPP__ 1

#include <corelib/internal/internal.h>

#include <memory>

namespace corelib {

    template <typename T>
    using Scope = std::unique_ptr<T>;

    template <typename Type, class... Args>
    constexpr Scope<Type>
    MakeScope(Args &&...args)
    {
        return std::make_unique<Type>(std::forward<Args>(args)...);
    }

    template <typename T>
    using Weak = std::weak_ptr<T>;

    template <typename T>
    using Ref = std::shared_ptr<T>;

    template <typename Type, class... Args>
    constexpr Ref<Type>
    MakeRef(Args &&...args)
    {
        return std::make_shared<Type>(std::forward<Args>(args)...);
    }

} // namespace corelib

#endif // __CORELIB_MEMORY_HPP__
