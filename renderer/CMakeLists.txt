cmake_minimum_required(VERSION 3.10)
project(renderer)

add_library(renderer STATIC
    src/RenderLampAPI.cpp
)

target_include_directories(renderer 
    PUBLIC
        ${PROJECT_SOURCE_DIR}/include
)

target_link_libraries(renderer PUBLIC nlohmann_json::nlohmann_json glm::glm Arca)