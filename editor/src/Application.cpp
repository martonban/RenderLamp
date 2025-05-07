#include "Application.hpp"

void Application::Init() {
    
    ArcaConfig arcaConfig {std::string{"test/url"}};
    arcaConfig.AddValue(std::string{"test"}, std::string{"1.234"});
    int i = arcaConfig.GetIntValue(std::string{"window_width"});
    std::cout << i << std::endl;
    float f = arcaConfig.GetFloatValue(std::string{"test"});
    std::cout << f << std::endl;
}

void Application::Start() {
    Window editorWindow = Window(1800, 900);
    editorWindow.Start();
}