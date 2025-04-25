#include "Application.hpp"

void Application::Init() {
    // Ensure Arca is defined and CreateDirectory is implemented
    Arca arca{};


    arca.CreateDirectory(std::string{"C:/RenderLamp"}, std::string{"Test"} );

}

void Application::Start() {
    Window editorWindow = Window(1800, 900);
    editorWindow.Start();
}