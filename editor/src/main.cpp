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
#include "BuildSystem.hpp"
#include "Arca.hpp"

int main(void) {
    // PREPARE ARCA INSTANCE
    Arca::InitArcaInstance("RenderLamp");

    // BUILDING ARCA INSTANCE
    if(Arca::FetchArcaInstance()) {
        Arca::BuildArcaInstance();
        std::cout << "Arca instance has been de-serialized and build!" << std::endl;
    } else {
        BuildSystem& build = BuildSystem::GetInstance();
        build.ReleaseMode();
        build.ModuleBuild();
        build.Release();
    }


    // START APPLICATION
    Application& render_lamp_app = Application::GetInstance();
    render_lamp_app.Init();
    render_lamp_app.Start();

    return 0;
}