#include "systems/ProjectManagerSystem.hpp"

void ProjectManagerSystem::StartSystem() {
    // Get Arca Container
    projectList = Arca::GetArcaModule("Editor")->GetContainer("ProjectList");
}

