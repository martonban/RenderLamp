cmake_minimum_required(VERSION 3.10)
project(Arca)

file(GLOB ARCA_SOURCES src/*.cpp)

add_library(Arca STATIC
    ${ARCA_SOURCES}
)

target_include_directories(Arca 
    PUBLIC
        ${PROJECT_SOURCE_DIR}/include
)


target_link_libraries(Arca PRIVATE nlohmann_json::nlohmann_json)