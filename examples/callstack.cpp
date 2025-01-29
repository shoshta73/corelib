#include <corelib.hpp>

void
bar()
{
    corelib::CallstackNode node;
    corelib::println("bar called");
}

void
foo()
{
    corelib::CallstackNode node;

    for (int i = 0; i < 10; i++)
    {
        bar();
    }
}

int
main(void)
{
    corelib::CallstackNode main_node;
    foo();
}
