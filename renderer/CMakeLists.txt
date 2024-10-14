cmake_minimum_required(VERSION 3.8)
project(renderer)


add_library(renderer INTERFACE)
target_include_directories(renderer INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}")


file(GLOB_RECURSE RENDERER_SOURCES CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")
add_executable(renderer_test)
target_sources(renderer_test PRIVATE ${RENDERER_SOURCES} )
target_link_libraries(renderer_test PUBLIC profilerLib)