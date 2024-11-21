#ifndef RENDERER_RAYLIB_H
#define RENDERER_RAYLIB_H

#include "raylib.h"

#include "CameraSystem.h"

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