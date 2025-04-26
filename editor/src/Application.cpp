#include "Application.hpp"

void Application::Init() {
    Marathon marathon {std::string{"RenderLamp"}};
}

void Application::Start() {
    Window editorWindow = Window(1800, 900);
    editorWindow.Start();
}