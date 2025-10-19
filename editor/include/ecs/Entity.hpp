#ifndef ENTITY_HPP
#define ENTITY_HPP

#include <memory>
#include <vector>
#include <cstdint>

#include "components/Transform3D.hpp"
#include "Component.hpp"

class Entity {
public:
    Entity();
    Entity(const Transform3D& transform);
    void AddComponenet(const Component& component);
    ~Entity();
private:

    
};

#endif