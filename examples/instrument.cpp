#include <corelib.hpp>

void foo()
{
    corelib::InstrumentationTimer timer;
}

void bar(int counter)
{
    corelib::InstrumentationTimer timer;
    for (int i = 0; i < counter; i++)
    {
        corelib::InstrumentationTimer timer_loop_count{std::to_string(i).c_str()};
        {
            foo();
        }
    }
}

int main(void)
{
    corelib::Instrumentor::get().begin_session("test", "results.json");
    {
        corelib::InstrumentationTimer timer;
        {
            corelib::InstrumentationTimer timer_loop{"loop"};
            {
                for (int i = 0; i < 10; i++)
                {
                    corelib::InstrumentationTimer timer_loop_count{std::to_string(i).c_str()};
                    foo();
                    bar(i);
                }
            }
            timer_loop.stop();
        }
        timer.stop();
    }
    corelib::Instrumentor::get().end_session();

    return 0;
}
