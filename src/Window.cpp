#include "Window.h"

void Window::Start() {  
    InitWindow(window_width, window_height, "RenderLamp Editor");
    Loop();
}

void Window::Loop() {
    while (!WindowShouldClose()) {
        renderer.RenderLoop();
    }

    Close();
}

void Window::Close() {
    CloseWindow();
}