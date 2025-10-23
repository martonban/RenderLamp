#include "systems/scene/SceneManagerSystem.hpp"

void SceneManagerSystem::StartSystem() {
    // Get Arca Container
    int width = Arca::GetArcaModule("Editor")->GetContainer("EditorConfig")->GetValue<int>("WindowWidth");
    int height = Arca::GetArcaModule("Editor")->GetContainer("EditorConfig")->GetValue<int>("WindowHeight");
    mCurrentScene = std::make_unique<Scene>(width, height);
}

void SceneManagerSystem::CreateProject(const std::string projectName, const std::filesystem::path& projectPath, const Scene& scn) {

}

Scene& SceneManagerSystem::GetCurrentScene() {
    return *mCurrentScene;
}

void SceneManagerSystem::SaveProjectMetaData(const std::string& name, std::filesystem::path& path) {
    // Meta Data
    mProjectList->AddPair(name, path);
    mProjectList->Dispatch();
}

