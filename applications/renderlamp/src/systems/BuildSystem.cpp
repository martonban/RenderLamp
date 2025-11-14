#include "systems/BuildSystem.hpp"


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
        std::string editorConfigFileName = "EditorConfig";
        editorModule->CreateNewContainer(editorConfigFileName);
        editorModule->GetContainer(editorConfigFileName)->AddPair("WindowWidth", 1800);
        editorModule->GetContainer(editorConfigFileName)->AddPair("WindowHeight", 900);
        editorModule->GetContainer(editorConfigFileName)->AddPair("WindowName", std::string("RenderLamp Edtior"));
        editorModule->GetContainer(editorConfigFileName)->Dispatch();

        // TO-DO: Build a defeault Project

        std::string projectListFileName = "ProjectList";
        editorModule->CreateNewContainer(projectListFileName);
        editorModule->GetContainer(projectListFileName)->Dispatch();
        
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

void BuildSystem::CreateDefaultScene() {
    if (mReleasePipelineIsRunning) {
        // Default Scene Creation
        Scene defaultScene = Scene{1800, 900};
        Transform3D trs = Transform3D { Vector3{0.0, 0.0, 0.0} };
        auto ent1 = std::make_unique<Entity>(1, trs);
        SphereRenderComponent sp = SphereRenderComponent{ Vector3{0.0f, 0.0f, 0.0f}, 1.5f, 1 };
        ent1->AddComponent(std::make_unique<SphereRenderComponent>(sp));
        defaultScene.AddEntity(std::move(ent1));
        
        // Get Path to serialize
        std::shared_ptr<ArcaModule> editorModule = Arca::GetArcaModule("Editor");
        std::filesystem::path pathToDefaultScene = editorModule->GetPath() / "DefaultScene.json";

        // Serialize
        defaultScene.Serialize(pathToDefaultScene);
    }
}


void BuildSystem::BuildModeOn() {
    mBuildPipelineIsRunning = true;
}

void BuildSystem::ReleaseModeOn() {
    mReleasePipelineIsRunning = true;
}


bool BuildSystem::GetBuildPipelineIsRunning() {
    return mBuildPipelineIsRunning;
} 
bool BuildSystem::GetReleasePipelineIsRunning() {
    return mReleasePipelineIsRunning;
}