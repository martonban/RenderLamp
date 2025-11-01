#include "systems/scene/SceneManagerSystem.hpp"

void SceneManagerSystem::StartSystem() {
    // Get config data 
    int width = Arca::GetArcaModule("Editor")->GetContainer("EditorConfig")->GetValue<int>("WindowWidth");
    int height = Arca::GetArcaModule("Editor")->GetContainer("EditorConfig")->GetValue<int>("WindowHeight");
    std::filesystem::path path = Arca::GetArcaModule("Editor")->GetPath() / "DefaultScene.json";
    
    // Load Default Project
    mCurrentScene = std::make_shared<Scene>(width, height);
    mCurrentScene->Deserialize(path);

    mProjectList = Arca::GetArcaModule("Editor")->GetContainer("ProjectList");
}

void SceneManagerSystem::DeserializeSceneFromJson(const std::filesystem::path& scenePath) {
    mCurrentScene->Deserialize(scenePath);
}

// Note: If Arca and RenderLamp have a Mesh Assets support at this stage user will add meshes 
// throw the Edtior. In the ECS meshes and assets is just references to a file on the disk. 
// I have to copy the raw asset data and pack it to a .arca or some shit to have all the assets
// when you open the project reagarless of the original file 
void SceneManagerSystem::SaveSceneToProject(const std::string& name, const std::filesystem::path& path) {
    // Append to the Project List 
    std::filesystem::path p = path / name;
    mProjectList->AddPair(name, p);
    mProjectList->Dispatch();

    mCurrentProject = std::make_unique<Project>(name, path, mCurrentScene);
}

 void SceneManagerSystem::LoadSceneFromProject(const std::string& name) {
     std::filesystem::path path = mProjectList->GetValue<std::filesystem::path>(name) / (name + ".json");
     mCurrentProject = std::make_unique<Project>(path, mCurrentScene);
  }


Scene& SceneManagerSystem::GetCurrentScene() {
    return *mCurrentScene;
}
