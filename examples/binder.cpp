#include <corelib.hpp>

using CallBack = ::std::function<int(int, int)>;

int add(int a, int b)
{
  return b - a;
}

int foo(CallBack cb)
{
  return cb(1, 2);
}

int main()
{
  return foo(corelib::Bind<int, int, int>(add)());
}
