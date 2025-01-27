#include <corelib/callstack.hpp>

#include <fstream>
#include <string>
#include <thread>
#include <source_location>

#include <corelib/def.hpp>

namespace corelib {

  Callstack::Callstack(const ::std::string &filename)
  {
    last_ = 0;
    filename_ = filename;
  }

  Callstack::~Callstack()
  {
    ::std::ofstream file(filename_);
    if (!file.is_open())
    {
      return;
    }

    file << "thread_id,entry_idx,caller_idx,loc,name\n";

    for (auto &node : nodes_)
    {
      file << node.thread_id << ','
           << node.idx << ','
           << ((signed long)node.caller_idx) << ','
           << node.loc.file_name() << ':' << (node.loc.line()) << ','
           << node.loc.function_name() << '\n';
    }
    file.flush();
    file.close();
  }

  void Callstack::push(CallstackEntry &node)
  {
    node.idx = nodes_.size();
    if (nodes_.size() >= 1)
    {
      node.caller_idx = last_;
      last_ = node.idx;
    }
    nodes_.push_back(node);
  }

  void Callstack::pop(size idx)
  {
    last_ = nodes_[idx].caller_idx;
  }

  CallstackNode::CallstackNode(::std::source_location loc)
  {
    entry_.loc = loc;
    entry_.thread_id = ::std::hash<::std::thread::id>{}(::std::this_thread::get_id());

    Callstack::get().push(entry_);
  }

  CallstackNode::~CallstackNode()
  {
    Callstack::get().pop(entry_.idx);
  }

} // namespace corelib
