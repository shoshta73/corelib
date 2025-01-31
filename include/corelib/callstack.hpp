#ifndef __CORELIB_CALLSTACK_HPP__
#define __CORELIB_CALLSTACK_HPP__ 1

#include <corelib/internal/internal.hpp>

#include <source_location>
#include <thread>
#include <vector>

#include <corelib/def.hpp>

namespace corelib {

    struct CallstackEntry
    {
        ::std::source_location loc;
        size caller_idx = -1;
        size idx = 0;
        u32 thread_id;
    };

    class Callstack
    {
    public:
        Callstack(const ::std::string &filename = "callstack.csv");

        ~Callstack();

        static Callstack &
        get()
        {
            static Callstack instance;
            return instance;
        }

        void push(CallstackEntry &node);
        void pop(size idx);

    private:
        ::std::vector<CallstackEntry> nodes_;
        size last_;
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
