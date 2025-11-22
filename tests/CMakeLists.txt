cmake_minimum_required(VERSION 3.10)
project(RenderArcTests)

# Enable testing
enable_testing()

# Core library tests
add_subdirectory(core)

# Integration tests
add_subdirectory(integration)
