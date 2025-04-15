#ifndef RENDERER_RAYLIB_HPP
#define RENDERER_RAYLIB_HPP

#include "raylib.h"

#include "CameraSystem.hpp"

class RendererRayLib {
    public: 
        RendererRayLib() {
            cameraSystem.StartCamera();
        };
        void Start();
        void RenderLoop() {
             // Update Camera System
        cameraSystem.UpdateCamera();

        BeginDrawing();

            ClearBackground(RAYWHITE);

            BeginMode3D(cameraSystem.GetCameraInstance());
                // ECS UPDATE 
                DrawGrid(10, 1.0f);
                std::cout << GetFPS() << std::endl;
            EndMode3D();

          // Text

        EndDrawing();
        }

    private:
        CameraSystem cameraSystem;
};

#endif