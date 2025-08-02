#include "Window.hpp"


void Window::AttachRenderer(RenderingSystem& renderer) { 
    mRenderer = &renderer;
}
void Window::Start() {  
    SetTargetFPS(60);
    InitWindow(mWindowWidth, mWindowHeight, "RenderLamp Editor");
    mRenderer->RenderingAllocation();
    WindowLoop();
}

void Window::WindowLoop() {
    while (!WindowShouldClose()) {
        BeginDrawing();
        mRenderer->Render();
        mRenderer->DrawFramebuffer();
        EndDrawing();
    }
    Close();
}

void Window::Close() {
    mRenderer->DestroyRenderer();
    CloseWindow();
}