#ifndef __CORELIB_CALLSTACK_HPP__
#define __CORELIB_CALLSTACK_HPP__ 1

#include <cstdint>
#include <source_location>
#include <thread>
#include <vector>

namespace corelib {

  struct CallstackEntry
  {
    ::std::source_location loc;
    ::std::size_t caller_idx = -1;
    ::std::size_t idx = 0;
    ::std::uint32_t thread_id;
  };

  class Callstack
  {
  public:
    Callstack(const ::std::string &filename = "callstack.csv");

    ~Callstack();

    static Callstack &get()
    {
      static Callstack instance;
      return instance;
    }

    void push(CallstackEntry &node);
    void pop(size_t idx);

  private:
    ::std::vector<CallstackEntry> nodes_;
    ::std::size_t last_;
    ::std::string filename_;
  };

  class CallstackNode
  {
  public:
    CallstackNode(::std::source_location loc = ::std::source_location::current());
    ~CallstackNode();

  private:
    CallstackEntry entry_;
  };

} // namespace corelib

#endif // __CORELIB_CALLSTACK_HPP__
