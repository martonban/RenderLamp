#include "systems/ProjectManagerSystem.hpp"

void ProjectManagerSystem::StartSystem() {
    // Get Arca Container
    mProjectList = Arca::GetArcaModule("Editor")->GetContainer("ProjectList");

}

void ProjectManagerSystem::CreateProject(const std::string& name, std::filesystem::path& path) {
    // Meta Data
    mProjectList->AddPair(name, path);
    mProjectList->Dispatch();
}

