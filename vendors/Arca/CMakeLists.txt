cmake_minimum_required(VERSION 3.10)
project(Arca)

add_library(Arca STATIC
    src/ArcaIO.cpp
)

target_include_directories(Arca 
    PUBLIC
        ${PROJECT_SOURCE_DIR}/include
)


target_link_libraries(Arca PRIVATE nlohmann_json::nlohmann_json)