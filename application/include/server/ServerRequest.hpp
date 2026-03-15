#pragma once

#include <filesystem>

enum ServerRequestTypes {
    ADD_NEW_PROJECT,
    LOAD_ALL_PROJECTS,
    RUN_TEST_RENDER
};


typedef struct ServerRequest {
    ServerRequestTypes type;
    std::filesystem::path path;
} ServerRequest;