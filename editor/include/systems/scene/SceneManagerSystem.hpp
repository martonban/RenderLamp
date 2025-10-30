#ifndef SCENE_MANAGER_SYSTEM_HPP
#define SCENE_MANAGER_SYSTEM_HPP

#include "Arca.hpp"
#include "systems/scene/Scene.hpp"
#include "systems/project/ProjectManagerSystem.hpp"
#include "systems/project/Project.hpp"

#include <memory>

class SceneManagerSystem {
    public: 
        static SceneManagerSystem& GetInstance() {
            static SceneManagerSystem instance;
            return instance;
        }
        void StartSystem();
        void DeserializeSceneFromJson(const std::filesystem::path& scenePath);
        Scene& GetCurrentScene();

    protected:
        SceneManagerSystem() = default;
    private:
        std::unique_ptr<Scene> mCurrentScene;
        std::unique_ptr<ProjectManagerSystem> mProjectManager;

        SceneManagerSystem(const SceneManagerSystem&) = delete;
        SceneManagerSystem& operator=(const SceneManagerSystem&) = delete;
};

#endif