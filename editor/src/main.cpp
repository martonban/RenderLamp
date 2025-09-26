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
    

    // TODO
    // Module absolute path 


    // Arca Asset Test 
    ArcaAsset asset { R"(C:\Project)", "output", ".ppm" };

    std::ostringstream oss;
    oss << "P3\n" << 100 << ' ' << 100 << "\n255\n";

    for (int j = 0; j < 100; j++) {
        for (int i = 0; i < 100; i++) {
            auto r = double(i) / (100-1);
            auto g = double(j) / (100-1);
            auto b = 0.0;

            int ir = int(255.999 * r);
            int ig = int(255.999 * g);
            int ib = int(255.999 * b);
            oss << ir << ' ' << ig << ' ' << ib << '\n';
        }
    }

    asset.AddStream(oss);




    // START APPLICATION
    Application& render_lamp_app = Application::GetInstance();
    render_lamp_app.Init();
    render_lamp_app.Start();

    return 0;
}