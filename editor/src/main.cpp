#include "Application.hpp"

int main(void)
{
    // Renderer Testing
    

    // Editor 
    Application& render_lamp_app = Application::GetInstance();
    render_lamp_app.Init();
    render_lamp_app.Start();

    return 0;
}