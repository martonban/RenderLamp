cmake_minimum_required(VERSION 3.10)

file(GLOB_RECURSE MY_SOURCES CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")
# Create the RenderLamp executable from the source files
add_executable(RenderLamp "${MY_SOURCES}")
target_include_directories(RenderLamp PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/include/")


if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET RenderLamp PROPERTY CXX_STANDARD 20)
endif()


target_link_libraries(RenderLamp PRIVATE raylib renderer nlohmann_json::nlohmann_json ImGui rlImGui)