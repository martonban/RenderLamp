cmake_minimum_required(VERSION 3.8)
project(RenderLampTest)


include(FetchContent)
include(CTest)


# Google Test Dependencies
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()
# Test
if(BUILD_TESTING)
file(GLOB_RECURSE TEST_SOURCES CONFIGURE_DEPENDS "${PROJECT_SOURCE_DIR}/tests/*.cpp")
  add_executable(RenderLampTest ${TEST_SOURCES})
  target_link_libraries(RenderLampTest PRIVATE gtest_main raylib renderer nlohmann_json::nlohmann_json)
  include(GoogleTest)
  gtest_discover_tests(RenderLampTest)
endif()