#ifndef MR_LOG_HPP
#define MR_LOG_HPP

#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_color_sinks.h>

#ifndef MR_DISABLE_LOGGING

#ifndef MR_LOG_LEVEL
#define MR_LOG_LEVEL spdlog::level::debug
#endif // MR_LOG_LEVEL

namespace mr::detail {
inline std::shared_ptr<spdlog::logger> get_logger() {
  static auto logger = []{
    auto logger = spdlog::stderr_color_mt("multi_robot");

    logger->set_pattern("%^%l: %v%$");

    logger->set_level(MR_LOG_LEVEL);
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
