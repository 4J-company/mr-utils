find_package(libassert REQUIRED)
find_package(Boost REQUIRED)
find_package(spdlog REQUIRED)

set(MR_UTILS_DEPENDENCIES libassert::assert spdlog::spdlog boost::boost)
