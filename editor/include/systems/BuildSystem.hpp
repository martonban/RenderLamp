#ifndef BUILD_SYSTEM_HPP
#define BUILD_SYSTEM_HPP

#include "Arca.hpp"
#include "systems/scene/Scene.hpp"
#include "ecs/Entity.hpp"
#include "ecs/Component.hpp"
#include "components/SphereRenderComponent.hpp"


class BuildSystem {
    public:
        // Insntace Realted Funtions
        static BuildSystem& GetInstance() {
            static BuildSystem instance;
            return instance;
        }

        void ModuleBuild();
        void Release();

        void AddEditorDefaultConfig();
        void AddRendererDefaultConfig();
        void CreateDefaultScene();

        void BuildModeOn();
        void ReleaseModeOn();

        bool GetBuildPipelineIsRunning();
        bool GetReleasePipelineIsRunning();
    protected:
        BuildSystem() = default;
    private:
        // Instace realated guard functions 
        BuildSystem(const BuildSystem&) = delete;
        BuildSystem& operator=(const BuildSystem&) = delete;
        bool mBuildPipelineIsRunning = false;
        bool mReleasePipelineIsRunning = false;
};

#endif