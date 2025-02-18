cmake_minimum_required(VERSION 3.8)

# Add Google Test
include(GoogleTest)

# Define the test executable
add_executable(RenderLampTestExecutable first_test.cpp)

# Link the test executable against gtest and gtest_main
target_link_libraries(RenderLampTestExecutable gtest gtest_main)

# Discover and add tests
gtest_discover_tests(RenderLampTestExecutable)