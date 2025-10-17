#include "Application.hpp"

void Application::Init() {
    BuildSystem& build = BuildSystem::GetInstance();
    build.AddEditorDefaultConfig();
    build.AddRendererDefaultConfig();
}

void Application::Start() {
    // Get Editor Config 
    std::shared_ptr<ArcaContainer> editorDefaultValues = Arca::GetArcaModule("Editor")->GetContainer("EditorConfig");
    int height = editorDefaultValues->GetValue<int>("WindowWidth");
    int width = editorDefaultValues->GetValue<int>("WindowHeight");
    
    // Subsystems Init
    auto renderer = std::make_unique<RealTimeRenderingSystem>(height, width);
    auto ecsSystem = std::make_unique<SceneManagerSystem>();
    auto editorWindow = std::make_unique<Window>(height, width);

    // Window Attachment
    editorWindow->AttachRenderer(std::move(renderer));
    editorWindow->Start();
}