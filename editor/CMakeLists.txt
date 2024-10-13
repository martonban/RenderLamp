include(FetchContent)

set(RAYLIB_VERSION 5.0)
FetchContent_Declare(
  raylib
  URL https://github.com/raysan5/raylib/archive/refs/tags/${RAYLIB_VERSION}.tar.gz
  FIND_PACKAGE_ARGS ${RAYLIB_VERSION}
)
set(BUILD_EXAMPLES OFF CACHE INTERNAL "")
FetchContent_MakeAvailable(raylib)

# Add source to this project's executable.
file(GLOB RenderLamp_SRC "*.h" "*.cpp")  # Include all .cpp files

add_executable(RenderLamp ${RenderLamp_SRC})
target_link_libraries(${PROJECT_NAME} raylib)


if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET RenderLamp PROPERTY CXX_STANDARD 20)
endif()