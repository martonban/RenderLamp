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
#include "ArcaModule.hpp"
#include "ArcaContainer.hpp"



int main(void) {
    // PREPARE ARCA INSTANCE
    Arca::InitArcaInstance("RenderLamp");

    // BUILDING ARCA INSTANCE
    if(Arca::FetchArcaInstance()) {
        Arca::BuildArcaInstance();
        std::cout << "Arca instance has been de-serialized and build!" << std::endl;
    } else {
        Arca::CreateArcaInstance();
        
        Arca::AddCreator("Márton Bán");

        Arca::CreateModule("Editor");

        // Build the instance
        if(Arca::ReleaseArcaInstance()) {
            std::cout << "Arca Instance has been created!" << std::endl;
        }
    }

    // ------------------------------------------------------------
    //                        RELASE MODE
    // ------------------------------------------------------------

    /*
    std::shared_ptr<ArcaModule> editorModule = Arca::GetArcaModule("Editor");
    std::string config1Name = "EditorConfig";
    editorModule->CreateNewContainer(config1Name);
    editorModule->GetContainer(config1Name)->AddPair("WindowWidth", 1800);
    editorModule->GetContainer(config1Name)->AddPair("WindowHeight", 900);
    editorModule->GetContainer(config1Name)->AddPair("WindowName", std::string("RenderLamp Edtior"));
    editorModule->GetContainer(config1Name)->Dispatch();
    editorModule->Serialize();
    */

    
    
    std::shared_ptr<ArcaModule> editorModule = Arca::GetArcaModule("Editor");
    std::string config1Name = "EditorConfig";
    int h = editorModule->GetContainer(config1Name)->GetValue<int>("WindowHeight");
    std::cout << "------------------------" << std::endl;
    std::cout << h << std::endl;
    std::cout << "------------------------" << std::endl;
    editorModule->GetContainer(config1Name)->AddPair("Pina", std::string("Pina"));
    editorModule->GetContainer(config1Name)->Dispatch();



    // START APPLICATION
    Application& render_lamp_app = Application::GetInstance();
    render_lamp_app.Init();
    render_lamp_app.Start();

    return 0;
}