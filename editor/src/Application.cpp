#include "Application.hpp"

void Application::Init() {
    BuildSystem& build = BuildSystem::GetInstance();
    build.AddEditorDefaultConfig();
    build.AddRendererDefaultConfig();
}

void Application::Start() {
    std::shared_ptr<ArcaContainer> editorDefaultValues = Arca::GetArcaModule("Editor")->GetContainer("EditorConfig");
    int height = editorDefaultValues->GetValue<int>("WindowWidth");
    int width = editorDefaultValues->GetValue<int>("WindowHeight");
    Window editorWindow = Window(height, width);
    RealTimeRenderingSystem renderer = RealTimeRenderingSystem{ height, width };
    editorWindow.AttachRenderer(renderer);
    editorWindow.Start();
}