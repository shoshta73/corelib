#include <corelib.hpp>

int
main()
{
    corelib::log::print("This is a message");
    corelib::log::trace("This is a message");
    corelib::log::debug("This is a message");
    corelib::log::info("This is a message");
    corelib::log::warning("This is a message");
    corelib::log::error("This is a message");
    corelib::log::critical("This is a message");
    corelib::log::fatal("This is a message");
    corelib::log::none("This is a message");
}
