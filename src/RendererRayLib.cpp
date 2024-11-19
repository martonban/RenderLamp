#include "RendererRayLib.h"

void RendererRayLib::RenderLoop() {
        UpdateCameraPro(&camera, { 0.01, 0.0, 0.0 }, {0.0}, 0.0);

        BeginDrawing();

            ClearBackground(RAYWHITE);

             BeginMode3D(camera);

                //DrawCube(cubePosition, 2.0f, 2.0f, 2.0f, RED);
                //DrawCubeWires(cubePosition, 2.0f, 2.0f, 2.0f, MAROON);
                //std::cout << GetMouseX() << " - " << GetMouseY() << std::endl;
                //std::cout << GetMouseDelta().x << " - " << GetMouseDelta().y << std::endl;
                DrawGrid(10, 1.0f);

            EndMode3D();

            DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);

        EndDrawing();
}