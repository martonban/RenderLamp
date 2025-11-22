cmake_minimum_required(VERSION 3.10)

# Integration tests
add_executable(TestIntegration
    TestIntegration.cpp
)

target_link_libraries(TestIntegration
    PRIVATE
        renderer
        Arca
        nlohmann_json::nlohmann_json
        glm::glm
        GTest::gtest
        GTest::gtest_main
)

target_include_directories(TestIntegration
    PRIVATE
        ${CMAKE_SOURCE_DIR}/core/Arca/include
        ${CMAKE_SOURCE_DIR}/core/BuzzRenderer/include
)

# Register the test with CTest
add_test(NAME TestIntegration COMMAND TestIntegration)
