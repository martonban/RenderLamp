#include "Window.hpp"

void Window::Start() {  
    InitWindow(window_width, window_height, "RenderLamp Editor");
    Loop();
}

void Window::Loop() {
    while (!WindowShouldClose()) {
        BeginDrawing();

        ClearBackground(RAYWHITE);

        DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);

    EndDrawing();
    }

    Close();
}

void Window::Close() {
    CloseWindow();
}