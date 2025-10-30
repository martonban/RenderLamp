#ifndef PROJECT_MANAGER_SYSTEM_HPP
#define PROJECT_MANAGER_SYSTEM_HPP

#include "Arca.hpp"
#include "systems/scene/Scene.hpp"

class ProjectManagerSystem {
    public: 
        ProjectManagerSystem(const std::string& containerName);
        bool LoadProject(const std::string& projectName);
        std::unique_ptr<Scene> GetCurrentScene();
    private:
        std::shared_ptr<ArcaContainer> mProjectList;
};

#endif