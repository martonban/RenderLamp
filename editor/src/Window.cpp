#include "Window.hpp"

void Window::Start() {  
    InitWindow(window_width, window_height, "RenderLamp Editor");
    camera.position = Vector3 { 10.0f, 10.0f, 10.0f }; // Camera position
    camera.target = Vector3 { 0.0f, 0.0f, 0.0f };      // Camera looking at point
    camera.up = Vector3 { 0.0f, 1.0f, 0.0f };          // Camera up vector (rotation towards target)
    camera.fovy = 45.0f;                                // Camera field-of-view Y
    camera.projection = CAMERA_PERSPECTIVE; 
    Loop();
}

void Window::Loop() {
    while (!WindowShouldClose()) {
        UpdateCamera(&camera, CAMERA_FREE);
        ClearBackground(RAYWHITE);
        BeginDrawing();
         BeginMode3D(camera);
            sp.Update();
          EndMode3D();
    EndDrawing();
    }

    Close();
}

void Window::Close() {
    CloseWindow();
}