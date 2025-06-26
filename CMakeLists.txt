cmake_minimum_required(VERSION 3.10)
project(RenderLamp)


include(FetchContent)

# Raylib dependences
set(RAYLIB_VERSION 5.5)
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

# Google Test Dependencies
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# GLM Dependencies
FetchContent_Declare(
	glm
	GIT_REPOSITORY	https://github.com/g-truc/glm.git
	GIT_TAG 	bf71a834948186f4097caa076cd2663c69a10e1e #refs/tags/1.0.1
)

FetchContent_MakeAvailable(glm)


# Arca 
#FetchContent_Declare(
#  Arca
#  URL https://github.com/martonban/Arca/releases/download/v0.0.1/Arca.zip
#)
#FetchContent_MakeAvailable(Arca)

# Enable testing
enable_testing()

add_subdirectory(editor)
add_subdirectory(renderer)
add_subdirectory(thirdparty/rlImGui)
add_subdirectory(thirdparty/imgui)
