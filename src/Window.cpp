#include "Window.h"

void Window::Start() {  
    InitWindow(window_width, window_height, "RenderLamp Editor");
    current_scene.Start();
    Loop();
}

void Window::Loop() {
    while (!WindowShouldClose()) {
        current_scene.Tick();
    }

    Close();
}

void Window::Close() {
    CloseWindow();
}