cmake_minimum_required(VERSION 3.8)
project(RenderLamp)

include(FetchContent)


# Sub-directories
add_subdirectory("renderer")
add_subdirectory("tests")


file(GLOB_RECURSE MY_SOURCES CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")
add_executable(RenderLamp "${MY_SOURCES}")

target_include_directories(RenderLamp PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include/")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET RenderLamp PROPERTY CXX_STANDARD 20)
endif()


# Raylib dependences
set(RAYLIB_VERSION 5.0)
FetchContent_Declare(
  raylib
  URL https://github.com/raysan5/raylib/archive/refs/tags/${RAYLIB_VERSION}.tar.gz
  FIND_PACKAGE_ARGS ${RAYLIB_VERSION}
)
set(BUILD_EXAMPLES OFF CACHE INTERNAL "")
FetchContent_MakeAvailable(raylib)


# Json Dependencies
FetchContent_Declare(json URL https://github.com/nlohmann/json/releases/download/v3.11.3/json.tar.xz)
FetchContent_MakeAvailable(json)

# Add Dependencies
target_link_libraries(${PROJECT_NAME} PRIVATE raylib renderer nlohmann_json::nlohmann_json)




