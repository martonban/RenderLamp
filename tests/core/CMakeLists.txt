cmake_minimum_required(VERSION 3.10)

# Test for Arca library
add_executable(TestArca
    TestArca.cpp
)

target_link_libraries(TestArca
    PRIVATE
        Arca
        nlohmann_json::nlohmann_json
        GTest::gtest
        GTest::gtest_main
)

target_include_directories(TestArca
    PRIVATE
        ${CMAKE_SOURCE_DIR}/core/Arca/include
)

# Register the test with CTest
add_test(NAME TestArca COMMAND TestArca)

# Test for BuzzRenderer library
add_executable(TestBuzzRenderer
    TestBuzzRenderer.cpp
)

target_link_libraries(TestBuzzRenderer
    PRIVATE
        renderer
        nlohmann_json::nlohmann_json
        glm::glm
        GTest::gtest
        GTest::gtest_main
)

target_include_directories(TestBuzzRenderer
    PRIVATE
        ${CMAKE_SOURCE_DIR}/core/BuzzRenderer/include
)

# Register the test with CTest
add_test(NAME TestBuzzRenderer COMMAND TestBuzzRenderer)
