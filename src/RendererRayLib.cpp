#include "RendererRayLib.h"

void RendererRayLib::Start() {
    // Camera System Init
    // ECS Init
}


void RendererRayLib::RenderLoop() {
        // Update Camera System
        UpdateCameraPro(&camera, { 0.001, 0.0, 0.0 }, {0.0}, 0.0);

        BeginDrawing();

            ClearBackground(RAYWHITE);

             BeginMode3D(camera);
                // ECS UPDATE 
                DrawGrid(10, 1.0f);

            EndMode3D();

            DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);

        EndDrawing();
}