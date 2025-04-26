cmake_minimum_required(VERSION 3.10)
project(renderer)

add_library(renderer STATIC
    src/renderer.cpp
)

target_include_directories(renderer 
    PUBLIC
        ${PROJECT_SOURCE_DIR}/include
)

add_executable(renderer_binary
    src/main.cpp
)

target_link_libraries(renderer_binary
    PRIVATE 
        renderer
        glm::glm
)