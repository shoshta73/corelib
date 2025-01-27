#include <corelib.hpp>

int main(void)
{

  corelib::assert();
  corelib::assert(true);
  corelib::assert(false);

  corelib::assert(true, "This is a message");
  corelib::assert(false, "This is a message");

  corelib::assert(true, "This is a message: {}", 1);
  corelib::assert(false, "This is a message: {}", 1);

  return 0;
}
