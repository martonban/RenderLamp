#include "Window.hpp"

void Window::Start() {  
    InitWindow(window_width, window_height, "RenderLamp Editor");
    Loop();
}

void Window::Loop() {
    while (!WindowShouldClose()) {
        
    }

    Close();
}

void Window::Close() {
    CloseWindow();
}