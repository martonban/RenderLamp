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

            DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);

        EndDrawing();
}