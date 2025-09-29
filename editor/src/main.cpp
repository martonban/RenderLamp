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
#include "ArcaAsset.hpp"


int main(void) {

    // PREPARE ARCA INSTANCE
    Arca::InitArcaInstance("RenderLamp");

    // BUILDING ARCA INSTANCE
    if(Arca::FetchArcaInstance()) {
        // Arca::BuildArcaInstance();
        Arca::ArcaTest();
        std::cout << "Arca instance has been de-serialized!" << std::endl;
        
    } else {
        Arca::CreateArcaInstance();
        
        Arca::AddCreator("Márton Bán");
        
        Arca::CreateModule(R"(C:\Project)");
        Arca::CreateModule(R"(C:\Project\Games)");

        // Build the instance
        if(Arca::ReleaseArcaInstance()) {
            std::cout << "Arca Instance has been created!" << std::endl;
        }
        Arca::ArcaTest();
    }


   

    // START APPLICATION
    Application& render_lamp_app = Application::GetInstance();
    render_lamp_app.Init();
    render_lamp_app.Start();

    return 0;
}