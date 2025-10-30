#include "systems/scene/SceneManagerSystem.hpp"

void SceneManagerSystem::StartSystem() {
    // Get config data 
    int width = Arca::GetArcaModule("Editor")->GetContainer("EditorConfig")->GetValue<int>("WindowWidth");
    int height = Arca::GetArcaModule("Editor")->GetContainer("EditorConfig")->GetValue<int>("WindowHeight");
    std::filesystem::path path = Arca::GetArcaModule("Editor")->GetPath() / "DefaultScene.json";
    
    // Load Default Project
    mCurrentScene = std::make_unique<Scene>(width, height);
    mCurrentScene->Deserialize(path);

    mProjectManager = std::make_unique<ProjectManagerSystem>("ProjectList");
}

void SceneManagerSystem::DeserializeSceneFromJson(const std::filesystem::path& scenePath) {
    mCurrentScene->Deserialize(scenePath);
}


Scene& SceneManagerSystem::GetCurrentScene() {
    return *mCurrentScene;
}
