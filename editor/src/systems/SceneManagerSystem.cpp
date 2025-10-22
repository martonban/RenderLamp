#include "systems/SceneManagerSystem.hpp"

void SceneManagerSystem::StartSystem() {
    // Get Arca Container
    mProjectList = Arca::GetArcaModule("Editor")->GetContainer("ProjectList");
}

void SceneManagerSystem::CreateProject(const std::string projectName, const std::filesystem::path& projectPath, const Scene& scn) {

}

std::unique_ptr<Scene> SceneManagerSystem::GetCurrentScene() {
    int width = Arca::GetArcaModule("Editor")->GetContainer("EditorConfig")->GetValue<int>("WindowWidth");
    int height = Arca::GetArcaModule("Editor")->GetContainer("EditorConfig")->GetValue<int>("WindowHeight");
    return std::make_unique<Scene>(width, height);
}

void SceneManagerSystem::SaveProjectMetaData(const std::string& name, std::filesystem::path& path) {
    // Meta Data
    mProjectList->AddPair(name, path);
    mProjectList->Dispatch();
}

