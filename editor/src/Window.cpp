#include "Window.hpp"

void Window::Init() {
    ProjectManagerSystem::GetInstance().StartSystem();
    mCurrentScene = std::make_unique<Scene>(mWindowWidth, mWindowHeight);
}

void Window::Start() {  
    SetTargetFPS(60);
    InitWindow(mWindowWidth, mWindowHeight, "RenderLamp Editor");
    mCurrentScene->Start();
    MainLoop();
}

void Window::MainLoop() {
    while (!WindowShouldClose()) {
        BeginDrawing();
            mCurrentScene->Update();
        EndDrawing();
    }
    Close();
}

void Window::Close() {
    mCurrentScene->Destroy();
    CloseWindow();
}