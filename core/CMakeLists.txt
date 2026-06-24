cmake_minimum_required(VERSION 3.10)
project(AdvancedRenderArcRenderer)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

file(GLOB_RECURSE ADVANCED_RENDERARC_RENDERER_SOURCES src/*.cpp)
file(GLOB_RECURSE ADVANCED_RENDERARC_RENDERER_HEADERS include/*.h include/*.hpp)

add_library(AdvancedRenderArcRenderer STATIC
    ${ADVANCED_RENDERARC_RENDERER_SOURCES}
)

set_target_properties(AdvancedRenderArcRenderer PROPERTIES
    PUBLIC_HEADER "${ADVANCED_RENDERARC_RENDERER_HEADERS}"
)

target_include_directories(AdvancedRenderArcRenderer
    PUBLIC
        ${PROJECT_SOURCE_DIR}/include
)


target_link_libraries(AdvancedRenderArcRenderer PUBLIC Arca nlohmann_json::nlohmann_json glm::glm)