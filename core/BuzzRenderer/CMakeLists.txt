cmake_minimum_required(VERSION 3.10)
project(renderer)


file(GLOB RENDERER_SOURCES src/*.cpp)

add_library(renderer STATIC
    ${RENDERER_SOURCES}
)

target_include_directories(renderer 
    PUBLIC
        ${PROJECT_SOURCE_DIR}/include
)

target_link_libraries(renderer PUBLIC nlohmann_json::nlohmann_json glm::glm Arca)