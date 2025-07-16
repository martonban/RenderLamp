#include "Window.hpp"

void Window::Start() {  
    InitWindow(mWindowWidth, mWindowHeight, "RenderLamp Editor");
    // 
    WindowLoop();
}

void Window::WindowLoop() {
    while (!WindowShouldClose()) {
    }

    Close();
}

void Window::Close() {
    CloseWindow();
}