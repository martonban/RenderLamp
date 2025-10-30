#include "systems/project/ProjectManagerSystem.hpp"

ProjectManagerSystem::ProjectManagerSystem(const std::string& name) {
    mProjectList = Arca::GetArcaModule("Editor")->GetContainer(name);
}