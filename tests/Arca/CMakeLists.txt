# Arca Tests CMakeLists.txt
cmake_minimum_required(VERSION 3.10)

# Add test executable
add_executable(arca_tests
    test_arca.cpp
)

# Link necessary libraries
target_link_libraries(arca_tests
    gtest_main
    gmock_main
    Arca
    nlohmann_json::nlohmann_json
)

# Include directories
target_include_directories(arca_tests PRIVATE
    ../../vendors/Arca/include
)

# Add test to CTest
include(GoogleTest)
gtest_discover_tests(arca_tests)
