#include "Application.hpp"

void Application::Init() {
}

void Application::Start() {
    Window editorWindow = Window(1800, 900);
    RenderingSystem renderer = RenderingSystem{ 1800, 900 };
    editorWindow.AttachRenderer(renderer);
    editorWindow.Start();
}