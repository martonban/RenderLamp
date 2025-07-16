//------------------------------------------------------------------------------------------------
//                                          RenderLamp
//                                      Márton Bán (C) 2024
//	
//  RenderLamp is a 3D DCC tool featuring a CPU-based ray tracer. The software consists of three 
//  main components: the DCC tool itself, and a rendering library and project management library 
//  collectively named as Arca (root/vendors/Arca).
//
//  This is the application's entry point.
//------------------------------------------------------------------------------------------------

#include "Application.hpp"


int main(void) {
    // Editor 
    Application& render_lamp_app = Application::GetInstance();
    render_lamp_app.Init();
    render_lamp_app.Start();

    return 0;
}