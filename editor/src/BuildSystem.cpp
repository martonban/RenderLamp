#include "BuildSystem.hpp"


void BuildSystem::ModuleBuild() {
    Arca::CreateArcaInstance();
    Arca::AddCreator("Márton Bán");
    Arca::CreateModule("Editor");
    Arca::CreateModule("Renderer");
}

void BuildSystem::Release() {
    // Build the instance
    if(Arca::ReleaseArcaInstance()) {
        std::cout << "Arca Instance has been created!" << std::endl;
    }
}


void BuildSystem::AddEditorDefaultConfig() {
    if(mReleasePipelineIsRunning) {
        std::shared_ptr<ArcaModule> editorModule = Arca::GetArcaModule("Editor");
        std::string config1Name = "EditorConfig";
        editorModule->CreateNewContainer(config1Name);
        editorModule->GetContainer(config1Name)->AddPair("WindowWidth", 1800);
        editorModule->GetContainer(config1Name)->AddPair("WindowHeight", 900);
        editorModule->GetContainer(config1Name)->AddPair("WindowName", std::string("RenderLamp Edtior"));
        editorModule->GetContainer(config1Name)->Dispatch();
        editorModule->Serialize();
    }
}

void BuildSystem::AddRendererDefaultConfig() {
    if(mReleasePipelineIsRunning) {
        std::shared_ptr<ArcaModule> rendererModule = Arca::GetArcaModule("Renderer");
        std::string configName = "DefaultBuzzRendererSettings";
        rendererModule->CreateNewContainer(configName);
        
    }
}


void BuildSystem::BuildMode() {
    mBuildPipelineIsRunning = true;
}

void BuildSystem::ReleaseMode() {
    mReleasePipelineIsRunning = true;
}
