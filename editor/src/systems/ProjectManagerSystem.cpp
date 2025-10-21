#include "systems/ProjectManagerSystem.hpp"

void ProjectManagerSystem::StartSystem() {
    // Get Arca Container
    mProjectList = Arca::GetArcaModule("Editor")->GetContainer("ProjectList");
}

std::unique_ptr<Scene> ProjectManagerSystem::LoadDefaultScene() {
    int width = Arca::GetArcaModule("Editor")->GetContainer("EditorConfig")->GetValue<int>("WindowWidth");
    int height = Arca::GetArcaModule("Editor")->GetContainer("EditorConfig")->GetValue<int>("WindowHeight");
    return std::make_unique<Scene>(width, height);
}

void ProjectManagerSystem::CreateProject(const std::string& name, std::filesystem::path& path) {
    // Meta Data
    mProjectList->AddPair(name, path);
    mProjectList->Dispatch();
}

