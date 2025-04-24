#include "Application.hpp"

void Application::Init() {
    Arca arca("/RenderLamp/ArcaInstance.txt");
}

void Application::Start() {
    Window editorWindow = Window(1800, 900);
    editorWindow.Start();
}