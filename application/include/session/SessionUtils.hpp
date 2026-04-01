#pragma once

#include <string>
#include <filesystem>

namespace RenderLamp {
    enum RenderEngine {
        POWDER_RENDERER = 0,
        RENDER_ARC_PRO_ENGINE = 1
    };

    enum LightSimMode {
        RAY_TRACING = 0,
        PATH_TRACING = 1
    };

    enum Device {
        SINGLE_THREADED_CPU = 0,
        AVX_MULTI_THREADED_CPU = 1,
        GPU = 2
    };

    typedef struct SessionSettings {
        std::string sessionName;
        std::filesystem::path sessionPath;
        RenderEngine engine;
        LightSimMode mode;
        Device device;
        int imageWidth;
        int imageHeight;
        int samples;
        int maxDepth;
        int frameRate;
    } SessionSettings;
}