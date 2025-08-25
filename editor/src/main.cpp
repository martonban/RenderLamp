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
#include "Arca.hpp"

int main(void) {

    // Arca Instance Created
    if(Arca::InitArcaInstance("ArcaInstance")) {
        std::cout << "Arca instance is creted!" << std::endl;
    } else {
        std::cout << "Arca instance has been corrupted!" << std::endl;
    }

    // Applicaton Data
    Arca::ArcaInstanceMetaDataSetup("RenderLamp", "Márton Bán");
    
    // Build Arca Instance
    

    // Application instance creted and stated
    Application& render_lamp_app = Application::GetInstance();
    render_lamp_app.Init();
    render_lamp_app.Start();

    return 0;
}