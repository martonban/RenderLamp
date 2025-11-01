#ifndef SCENE_MANAGER_SYSTEM_HPP
#define SCENE_MANAGER_SYSTEM_HPP

#include "Arca.hpp"
#include "systems/scene/Scene.hpp"
#include "systems/project/Project.hpp"

#include <memory>

class SceneManagerSystem {
    public: 
        static SceneManagerSystem& GetInstance() {
            static SceneManagerSystem instance;
            return instance;
        }

        // Scene System Lifetime 
        void StartSystem();

        // Serialization Functions
        void DeserializeSceneFromJson(const std::filesystem::path& scenePath);
        

        // Project Manager
        void SaveSceneToProject(const std::string& name, const std::filesystem::path& path);
        void LoadSceneFromProject(const std::string& name);

        // Getters
        Scene& GetCurrentScene();

    protected:
        SceneManagerSystem() = default;
    private:
        std::unique_ptr<Project> mCurrentProject;
        std::shared_ptr<Scene> mCurrentScene;
        std::shared_ptr<ArcaContainer> mProjectList;

        // Singleton classes
        SceneManagerSystem(const SceneManagerSystem&) = delete;
        SceneManagerSystem& operator=(const SceneManagerSystem&) = delete;
};

#endif