#ifndef SCENE_HPP
#define SCENE_HPP

#include <memory>
#include <cstdint>
#include <vector>
#include <filesystem>
#include <fstream>
#include <iostream>

#include "systems/RealTimeRenderingSystem.hpp"
#include "ecs/Component.hpp"
#include "ecs/Entity.hpp"

class Scene {
    public:
        Scene(const int& width, const int& height);
   
        void Start();
        void Update();
        void Destroy();

        void AddEntity(std::shared_ptr<Entity> newComponent);


        bool Serialize(const std::filesystem::path& outPath) const;
        nlohmann::json SceneToJson() const;
        
        bool Deserialize(const std::filesystem::path& outPath);
        void JsonToScene(const nlohmann::json& sceneJson);
    
    private:
        std::vector<std::shared_ptr<Entity>> mEntityVector;
        std::unique_ptr<RealTimeRenderingSystem> mRenderer;
};

#endif