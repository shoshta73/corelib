#ifndef CORELIB_INSTRUMENTOR_HPP
#define CORELIB_INSTRUMENTOR_HPP

#include <string>
#include <chrono>
#include <algorithm>
#include <fstream>
#include <thread>
#include <source_location>

namespace corelib {

  struct ProfileResult
  {
    std::string name;
    long long start, end;
    uint32_t thread_id;
  };

  struct InstrumentationSession
  {
    std::string name;
  };

  class Instrumentor
  {
  public:
    Instrumentor();

    void begin_session(const std::string &name, const std::string &filepath = "results.json");
    void end_session();
    void write_profile(const ProfileResult &result);

    static Instrumentor &get()
    {
      static Instrumentor instance;
      return instance;
    }

  private:
    void write_footer();
    void write_header();

    InstrumentationSession *current_session_;
    std::ofstream output_stream_;
    int profile_count_;
  };

  class InstrumentationTimer
  {
  public:
    InstrumentationTimer(const char *name = std::source_location::current().function_name());

    ~InstrumentationTimer();
    void stop();

  private:
    const char *name_;
    std::chrono::time_point<std::chrono::high_resolution_clock> start_timepoint_;
    bool stopped_;
  };

} // namespace corelib

#endif // CORELIB_INSTRUMENTOR_HPP
