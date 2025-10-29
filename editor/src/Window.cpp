#include "Window.hpp"

void Window::Init() {
    SceneManagerSystem::GetInstance().StartSystem();
    SceneManagerSystem::GetInstance().DeserializeSceneFromJson("C:/Project/ggg.json");
    //ProjectManagerSystem::GetInstance().LoadDefualtProject();
    mCurrentScene = &SceneManagerSystem::GetInstance().GetCurrentScene();

    //Transform3D trs = Transform3D {};
    //Transform3D trs2 = Transform3D { Vector3{1.0, 0.5, 1.0} };

    //auto ent1 = std::make_unique<Entity>(1, trs);
    //auto ent2 = std::make_unique<Entity>(2, trs2);

    //SphereRenderComponent sp = SphereRenderComponent{ Vector3{0.0f, 0.0f, 0.0f}, 1.5f, 1 };
    //ent1->AddComponent(std::make_unique<SphereRenderComponent>(sp));

    //mCurrentScene->AddEntity(std::move(ent1));
    //mCurrentScene->AddEntity(std::move(ent2));
}

void Window::Start() {
    // Image image;
    SetTargetFPS(60);
    InitWindow(mWindowWidth, mWindowHeight, "RenderLamp Editor");
    // SetWindowIcon(image);
    mCurrentScene->Start();
    MainLoop();
}

void Window::MainLoop() {
    while (!WindowShouldClose()) {
        if(IsKeyPressed(KEY_W)) {
            mCurrentScene->Serialize("C:/Project/ggg.json");
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