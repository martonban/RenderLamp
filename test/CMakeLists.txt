cmake_minimum_required(VERSION 3.8)

set(RenderLampTest RenderLampTestExecutable)

set(Sources
    first_test.cpp
)

add_executable(${RenderLampTest} ${Sources})

target_link_libraries(${RenderLampTest} PUBLIC gtest_main)

add_test(
    NAME ${RenderLampTest}
    COMMAND ${RenderLampTest}
)