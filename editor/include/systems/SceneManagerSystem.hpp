#ifndef SCENE_MANAGER_SYSTEM_HPP
#define SCENE_MANAGER_SYSTEM_HPP

#include "Arca.hpp"
#include "ecs/Scene.hpp"

#include <memory>

class SceneManagerSystem {
    public: 
        static SceneManagerSystem& GetInstance() {
            static SceneManagerSystem instance;
            return instance;
        }
        void StartSystem();
        void CreateProject(const std::string projectName, const std::filesystem::path& projectPath, const Scene& scn);
        std::unique_ptr<Scene> GetCurrentScene();

    protected:
        SceneManagerSystem() = default;
    private:
        std::shared_ptr<ArcaContainer> mProjectList;

        void SaveProjectMetaData(const std::string& name, std::filesystem::path& path);

        SceneManagerSystem(const SceneManagerSystem&) = delete;
        SceneManagerSystem& operator=(const SceneManagerSystem&) = delete;
};

#endif