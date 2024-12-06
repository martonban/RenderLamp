#include "RendererRayLib.h"

void RendererRayLib::Start() {
    // ECS Init
}


void RendererRayLib::RenderLoop() {
        // Update Camera System
        cameraSystem.UpdateCamera();

        BeginDrawing();

            ClearBackground(RAYWHITE);

            BeginMode3D(cameraSystem.GetCameraInstance());
                // ECS UPDATE 
                DrawGrid(10, 1.0f);

            EndMode3D();

          // Text

        EndDrawing();
}