#ifndef SCENE_HPP
#define SCENE_HPP

#include <memory>
#include <cstdint>
#include <vector>

#include "systems/RealTimeRenderingSystem.hpp"
#include "ecs/Component.hpp"
#include "ecs/Entity.hpp"

class Scene {
public:
    Scene(const int& width, const int& height);
    void Start();
    void Update();
    void Destroy();
private:
    std::unique_ptr<RealTimeRenderingSystem> mRenderer;
    
    std::map<uint64_t, std::shared_ptr<Entity>> mEntityList;
    std::map<uint64_t, std::shared_ptr<Component>> mComponentList;
};

#endif