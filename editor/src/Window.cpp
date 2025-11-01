#include "Window.hpp"

void Window::Init() {
    SceneManagerSystem::GetInstance().StartSystem();
    mCurrentScene = &SceneManagerSystem::GetInstance().GetCurrentScene();
}

void Window::Start() {
    // Image image;
    // SetWindowIcon(image);
    SetTargetFPS(60);
    InitWindow(mWindowWidth, mWindowHeight, "RenderLamp Editor");
    mCurrentScene->Start();
    MainLoop();
}

void Window::MainLoop() {
    while (!WindowShouldClose()) {
        // Load Project
        if(IsKeyPressed(KEY_R)) {
            mCurrentScene -> Destroy();
            SceneManagerSystem::GetInstance().LoadSceneFromProject("SecondProject");
            mCurrentScene = &SceneManagerSystem::GetInstance().GetCurrentScene();
            mCurrentScene -> Start();
        }

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