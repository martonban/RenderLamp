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
        rendererModule->GetContainer(configName)->AddPair("TargetRenderWidth", 1920);
        rendererModule->GetContainer(configName)->AddPair("TargetRenderHeight", 1080);
        rendererModule->GetContainer(configName)->AddPair("CameraFOV", 90.0);
        rendererModule->GetContainer(configName)->AddPair("FocalLength", 1.0);
        rendererModule->GetContainer(configName)->AddPair("SamplePerPixel", 250);
        rendererModule->GetContainer(configName)->AddPair("MaxDepth", 40);
        rendererModule->GetContainer(configName)->Dispatch();
        rendererModule->Serialize();
    }
}


void BuildSystem::BuildMode() {
    mBuildPipelineIsRunning = true;
}

void BuildSystem::ReleaseMode() {
    mReleasePipelineIsRunning = true;
}
