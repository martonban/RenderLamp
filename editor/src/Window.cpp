#include "Window.hpp"

void Window::Init() {
    ProjectManagerSystem::GetInstance().StartSystem();
    mSceneManager = std::make_unique<SceneManagerSystem>();
    mRenderer = std::make_unique<RealTimeRenderingSystem>(mWindowWidth, mWindowHeight, std::move(mSceneManager));

}

void Window::Start() {  
    SetTargetFPS(60);
    InitWindow(mWindowWidth, mWindowHeight, "RenderLamp Editor");
    mRenderer->RenderingAllocation();
    MainLoop();
}

void Window::MainLoop() {
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