#include "Application.hpp"

void Application::Init() {
    
    ArcaConfig arcaConfig {std::string{"test/url"}};
    arcaConfig.AddValue(std::string{"test"}, std::string{"Value"});
    std::string f = arcaConfig.GetStringValue(std::string{"test"});
    std::cout << f << std::endl;
}

void Application::Start() {
    Window editorWindow = Window(1800, 900);
    editorWindow.Start();
}