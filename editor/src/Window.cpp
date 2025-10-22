#include "Window.hpp"

void Window::Init() {
    SceneManagerSystem::GetInstance().StartSystem();
    //ProjectManagerSystem::GetInstance().LoadDefualtProject();
    mCurrentScene = &SceneManagerSystem::GetInstance().GetCurrentScene();
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