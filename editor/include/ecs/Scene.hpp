#ifndef SCENE_HPP
#define SCENE_HPP

#include <memory>
#include <cstdint>

#include "systems/RealTimeRenderingSystem.hpp"

class Scene {
public:
    Scene(const int& width, const int& height);
    void Start();
    void Update();
    void Destroy();
private:
    std::unique_ptr<RealTimeRenderingSystem> mRenderer;
    
    std::vector<std::shared_ptr<Entity>> mEntityList;
    std::vector<std::shared_ptr<Component>> mComponentList;
};

#endif