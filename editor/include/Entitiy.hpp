#ifndef ENTITY_HPP
#define ENTITY_HPP

#include <memory>
#include <vector>
#include <cstdint>

#include "Component.hpp"

class Entity {
public:
    void AddComponent(std::shared_ptr<Component> component);
    void RemoveComponenet(uint64_t id);
    void LogicUpdate();
    void RenderUpdate();
    virtual void RayTracerSerializer();
private:
    std::vector<std::shared_ptr<Component>> mComponentList;
};

#endif