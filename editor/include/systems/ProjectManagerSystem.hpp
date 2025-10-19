#ifndef PROJECT_MANAGER_SYSTEM_HPP
#define PROJECT_MANAGER_SYSTEM_HPP

#include "Arca.hpp"
#include "ecs/Scene.hpp"

#include <memory>

class ProjectManagerSystem {
    public: 
        static ProjectManagerSystem& GetInstance() {
            static ProjectManagerSystem instance;
            return instance;
        }
        void StartSystem();
        std::unique_ptr<Scene> LoadScene(const std::string& name);
        void CreateProject(const std::string& name, std::filesystem::path& path);
    protected:
        ProjectManagerSystem() = default;
    private:
        std::shared_ptr<ArcaContainer> mProjectList;
        std::unique_ptr<SceneManagerSystem> mSceneManagerSystem;
        ProjectManagerSystem(const ProjectManagerSystem&) = delete;
        ProjectManagerSystem& operator=(const ProjectManagerSystem&) = delete;
};

#endif