cmake_minimum_required(VERSION 3.27)
project(
  mr-utils
  VERSION 1.1.2
  LANGUAGES CXX
)

set(MR_UTILS_LIB_NAME mr-utils-lib)

include(cmake/deps.cmake)

add_library(${MR_UTILS_LIB_NAME} INTERFACE
  include/mr-utils/log.hpp
  include/mr-utils/assert.hpp
  include/mr-utils/containers.hpp
  include/mr-utils/misc.hpp
)
target_include_directories(${MR_UTILS_LIB_NAME} INTERFACE
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>
)
target_link_libraries(${MR_UTILS_LIB_NAME}      INTERFACE ${MR_UTILS_DEPENDENCIES})
target_compile_features(${MR_UTILS_LIB_NAME}    INTERFACE cxx_std_23)

install(TARGETS ${MR_UTILS_LIB_NAME}
        EXPORT mr-utilsTargets
        DESTINATION lib
)

install(DIRECTORY include/
        DESTINATION include
)

install(EXPORT mr-utilsTargets
        FILE mr-utilsConfig.cmake
        DESTINATION lib/cmake/mr-utils
)
