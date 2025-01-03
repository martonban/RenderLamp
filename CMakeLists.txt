cmake_minimum_required(VERSION 3.8)
project(RenderLamp)

include(FetchContent)

enable_testing()

add_subdirectory(editor)
add_subdirectory(renderer)
add_subdirectory(tests)

