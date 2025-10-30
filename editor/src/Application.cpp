#include "Application.hpp"

void Application::Init() {
    BuildSystem& build = BuildSystem::GetInstance();
    build.AddEditorDefaultConfig();
    build.AddRendererDefaultConfig();
    build.CreateDefaultScene();
}

void Application::Start() {
    // Get Editor Config 
    std::shared_ptr<ArcaContainer> editorDefaultValues = Arca::GetArcaModule("Editor")->GetContainer("EditorConfig");
    int height = editorDefaultValues->GetValue<int>("WindowWidth");
    int width = editorDefaultValues->GetValue<int>("WindowHeight");
    
    // Subsystems Init
    auto editorWindow = std::make_unique<Window>(height, width);

    // Window Start
    editorWindow->Init();
    editorWindow->Start();
}