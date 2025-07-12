#include "Window.hpp"

void Window::Start() {  
    InitWindow(mWindowWidth, mWindowHeight, "RenderLamp Editor");
    mCamera.position = Vector3 { 10.0f, 10.0f, 10.0f }; // Camera position
    mCamera.target = Vector3 { 0.0f, 0.0f, 0.0f };      // Camera looking at point
    mCamera.up = Vector3 { 0.0f, 1.0f, 0.0f };          // Camera up vector (rotation towards target)
    mCamera.fovy = 45.0f;                                // Camera field-of-view Y
    mCamera.projection = CAMERA_PERSPECTIVE; 
    Loop();
}

void Window::Loop() {
    while (!WindowShouldClose()) {
        UpdateCamera(&mCamera, CAMERA_FREE);
        ClearBackground(RAYWHITE);
        BeginDrawing();
         BeginMode3D(mCamera);
            // Components
          EndMode3D();
    EndDrawing();
    }

    Close();
}

void Window::Close() {
    CloseWindow();
}