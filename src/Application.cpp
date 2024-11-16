#include "Application.h"
#include "Window.h"

void Application::Init() {
    // This is currently empty
    // TODOs:
    // - Start Log system
    // - Start the Serializers/Parsers.
    // - Load Application resources such as GUI elements or existing project list etc.
}

void Application::Start() {
    // Later this is going to be expand.
    // For now I will open a basic 3D editor
    Window editor_window = Window(1800, 900);
    editor_window.Start();
}