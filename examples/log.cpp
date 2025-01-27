#include <corelib.hpp>

int main(void)
{
  corelib::log::debug("Hello, world!");
  corelib::log::info("Hello, world!");
  corelib::log::warn("Hello, world!");
  corelib::log::error("Hello, world!");
  corelib::log::critical("Hello, world!");
  corelib::log::fatal("Hello, world!");

  return 0;
}
