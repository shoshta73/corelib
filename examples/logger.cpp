#include <corelib.hpp>
using namespace corelib;

template <typename... Args>
using trace = log::NamedTrace<"trace", Args...>;
template <typename... Args>
using debug = log::NamedDebug<"debug", Args...>;
template <typename... Args>
using info = log::NamedInfo<"info", Args...>;
template <typename... Args>
using warning = log::NamedWarning<"warning", Args...>;
template <typename... Args>
using warn = warning<Args...>;
template <typename... Args>
using error = log::NamedError<"error", Args...>;
template <typename... Args>
using fatal = log::NamedFatal<"fatal", Args...>;

int main()
{
    log::trace("Hello, world!");
    log::debug("Hello, world!");
    log::info("Hello, world!");
    log::warning("Hello, world!");
    log::warn("Hello, world!");
    log::error("Hello, world!");
    log::fatal("Hello, world!");

    log::trace("Hello, {}!", "world");
    log::debug("Hello, {}!", "world");
    log::info("Hello, {}!", "world");
    log::warning("Hello, {}!", "world");
    log::warn("Hello, {}!", "world");
    log::error("Hello, {}!", "world");
    log::fatal("Hello, {}!", "world");

    trace("Hello, world!");
    debug("Hello, world!");
    info("Hello, world!");
    warning("Hello, world!");
    warn("Hello, world!");
    error("Hello, world!");
    fatal("Hello, world!");

    trace("Hello, {}!", "world");
    debug("Hello, {}!", "world");
    info("Hello, {}!", "world");
    warning("Hello, {}!", "world");
    warn("Hello, {}!", "world");
    error("Hello, {}!", "world");
    fatal("Hello, {}!", "world");

    print("Hello, world!");
    println("Hello, world!");
    print("Hello, {}!", "world");
    println("Hello, {}!", "world");

    return 0;
}
