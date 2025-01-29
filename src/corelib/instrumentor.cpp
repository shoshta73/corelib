#include <corelib/instrumentor.hpp>

#include <string>
#include <chrono>

namespace corelib {

    Instrumentor::Instrumentor()
        : current_session_(nullptr)
        , profile_count_(0)
    {
    }

    void
    Instrumentor::begin_session(const ::std::string &name, const ::std::string &filepath)
    {
        output_stream_.open(filepath);
        write_header();
        current_session_ = new InstrumentationSession{name};
    }

    void
    Instrumentor::end_session()
    {
        write_footer();
        output_stream_.close();
        delete current_session_;
        current_session_ = nullptr;
        profile_count_ = 0;
    }

    void
    Instrumentor::write_profile(const ProfileResult &result)
    {
        if (profile_count_++ > 0)
            output_stream_ << ",";

        ::std::string name = result.name;
        ::std::replace(name.begin(), name.end(), '"', '\'');

        output_stream_ << "{";
        output_stream_ << "\"cat\":\"function\",";
        output_stream_ << "\"dur\":" << (result.end - result.start) << ',';
        output_stream_ << "\"name\":\"" << name << "\",";
        output_stream_ << "\"ph\":\"X\",";
        output_stream_ << "\"pid\":0,";
        output_stream_ << "\"tid\":" << result.thread_id << ",";
        output_stream_ << "\"ts\":" << result.start;
        output_stream_ << "}";

        output_stream_.flush();
    }

    void
    Instrumentor::write_header()
    {
        output_stream_ << "{\"otherData\": {},\"traceEvents\":[";
        output_stream_.flush();
    }

    void
    Instrumentor::write_footer()
    {
        output_stream_ << "]}";
        output_stream_.flush();
    }

    InstrumentationTimer::InstrumentationTimer(const char *name)
        : name_(name)
        , stopped_(false)
    {
        start_timepoint_ = ::std::chrono::high_resolution_clock::now();
    }

    InstrumentationTimer::~InstrumentationTimer()
    {
        if (!stopped_)
            stop();
    }

    void
    InstrumentationTimer::stop()
    {
        auto endTimepoint = ::std::chrono::high_resolution_clock::now();

        i64 start = ::std::chrono::time_point_cast<::std::chrono::microseconds>(start_timepoint_).time_since_epoch().count();
        i64 end = ::std::chrono::time_point_cast<::std::chrono::microseconds>(endTimepoint).time_since_epoch().count();

        u32 threadID = ::std::hash<::std::thread::id>{}(::std::this_thread::get_id());
        Instrumentor::get().write_profile({name_, start, end, threadID});

        stopped_ = true;
    }

} // namespace corelib
