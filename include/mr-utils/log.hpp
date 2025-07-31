#ifndef MR_LOG_HPP
#define MR_LOG_HPP

#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_color_sinks.h>

#ifndef NDEBUG
namespace mr::detail {
inline std::shared_ptr<spdlog::logger> get_logger() {
    static auto logger = []{
        auto logger = spdlog::stderr_color_mt("multi_robot");

        // Customize level names to match original macros
        spdlog::level_strings custom_names;
        custom_names[spdlog::level::critical] = "FATAL";
        custom_names[spdlog::level::err] = "ERROR";
        custom_names[spdlog::level::warn] = "WARNING";
        custom_names[spdlog::level::info] = "INFO";
        custom_names[spdlog::level::debug] = "DEBUG";
        logger->set_level_strings(custom_names);

        // Set log pattern with color markers
        logger->set_pattern("%^%l: %v%$");

        // Set log level for debug builds
        logger->set_level(spdlog::level::debug);
        return logger;
    }();
    return logger;
}
} // namespace mr::detail

#define MR_LOG(level, ...) \
    mr::detail::get_logger()->log(level, __VA_ARGS__)

#else
#define MR_LOG(...) static_cast<void>(0)
#endif // NDEBUG

// Define specific log macros
#define MR_INFO(...)    MR_LOG(spdlog::level::info, __VA_ARGS__)
#define MR_DEBUG(...)   MR_LOG(spdlog::level::debug, __VA_ARGS__)
#define MR_WARNING(...) MR_LOG(spdlog::level::warn, __VA_ARGS__)
#define MR_ERROR(...)   MR_LOG(spdlog::level::err, __VA_ARGS__)
#define MR_FATAL(...)   MR_LOG(spdlog::level::critical, __VA_ARGS__)

#endif // MR_LOG_HPP
