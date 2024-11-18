#include "Window.h"



void Window::Start() {  
    
    InitWindow(window_width, window_height, "RenderLamp Editor");
    
    camera.position = {10.0, 10.0, 10.0};
    camera.target = { 0.0, 0.0, 0.0 };
    camera.up = { 0.0, 1.0, 0.0 };          
    camera.fovy = 45.0f;                                
    camera.projection = CAMERA_PERSPECTIVE;            

    Loop();
}

void Window::Loop() {
      while (!WindowShouldClose())
    {
        UpdateCameraPro(&camera, { 0.01, 0.0, 0.0 }, {0.0}, 0.0);

        BeginDrawing();

            ClearBackground(RAYWHITE);

             BeginMode3D(camera);

                DrawCube(cubePosition, 2.0f, 2.0f, 2.0f, RED);
                DrawCubeWires(cubePosition, 2.0f, 2.0f, 2.0f, MAROON);
                //std::cout << GetMouseX() << " - " << GetMouseY() << std::endl;
                std::cout << GetMouseDelta().x << " - " << GetMouseDelta().y << std::endl;
                DrawGrid(10, 1.0f);

            EndMode3D();

            DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);

        EndDrawing();
    }

    Close();
}

void Window::Close() {
    CloseWindow();
}