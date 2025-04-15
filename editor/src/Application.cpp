#include "Application.hpp"
#include "Window.hpp"


void Application::Init() {
    // Scene Manager
    // Renderer
    //
}

void Application::Start() {
    // For now I will open a basic 3D editor
    Window editor_window = Window(1800, 900);
    editor_window.Start();
}