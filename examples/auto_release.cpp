#include <corelib.hpp>

// we are simulating c api here

int *create_int(int value)
{
  corelib::print("create_int: {}", value);
  return new int(value);
}

void destroy_int(int *ptr)
{
  corelib::print("destroy_int: {}", *ptr);
  delete ptr;
}

int main()
{
  auto ptr = corelib::AutoRelease<int *>(create_int(42), destroy_int);

  auto foo = corelib::AutoRelease<int *>(); // empty
  foo = corelib::AutoRelease<int *>(create_int(24), destroy_int);
}
