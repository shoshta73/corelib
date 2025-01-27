#ifndef __CORELIB_AUTO_RELEASE_HPP__
#define __CORELIB_AUTO_RELEASE_HPP__ 1

#include <corelib/internal/internal.h>

#include <functional>
#include <ranges>

namespace corelib {

  template <class T, T Invalid = T{}>
  class AutoRelease
  {
  public:
    AutoRelease()
        : AutoRelease(Invalid)
    {
    }

    explicit AutoRelease(T obj, ::std::function<void(T)> deleter = nullptr)
        : obj_(obj)
        , deleter_(deleter)
    {
    }

    AutoRelease(const AutoRelease &) = delete;
    AutoRelease &operator=(const AutoRelease &) = delete;

    AutoRelease(AutoRelease &&other)
        : AutoRelease()
    {
      swap(other);
    }

    AutoRelease &operator=(AutoRelease &&other)
    {
      AutoRelease new_obj{::std::move(other)};
      swap(new_obj);

      return *this;
    }

    ~AutoRelease()
    {
      if ((obj_ != Invalid) && deleter_)
      {
        deleter_(obj_);
      }
    }

    T get() const
    {
      return obj_;
    }

    operator T() const
    {
      return obj_;
    }

    explicit operator bool() const
    {
      return obj_ != Invalid;
    }

    bool operator==(const AutoRelease &) const = default;
    bool operator!=(const AutoRelease &) const = default;

    void swap(AutoRelease &other)
    {
      ::std::ranges::swap(obj_, other.obj_);
      ::std::ranges::swap(deleter_, other.deleter_);
    }

  private:
    T obj_;
    ::std::function<void(T)> deleter_;
  };

} // namespace corelib

template <class T, T Invalid>
void swap(::corelib::AutoRelease<T, Invalid> &ar1, ::corelib::AutoRelease<T, Invalid> &ar2)
{
  ar1.swap(ar2);
}

#endif // __CORELIB_AUTO_RELEASE_HPP__
