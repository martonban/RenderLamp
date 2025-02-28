#ifndef RENDERER_RAYLIB_HPP
#define RENDERER_RAYLIB_HPP

#include "raylib.h"

#include "CameraSystem.hpp"

class RendererRayLib {
    // Functions 
    public: 
        RendererRayLib() {
            cameraSystem.StartCamera();
        };
        void Start();
        void RenderLoop();

    // Data Fields
    private:
        CameraSystem cameraSystem;
};

#endif