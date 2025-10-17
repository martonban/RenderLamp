#include "Window.hpp"


void Window::AttachRenderer(std::unique_ptr<RealTimeRenderingSystem> renderer) { 
    mRenderer = std::move(renderer);
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