#ifndef ENTITY_HPP
#define ENTITY_HPP

#include <memory>
#include <vector>
#include <cstdint>

#include "components/Transform3D.hpp"


class Entity {
public:
    Entity();
    Entity(const Transform3D& transform);
    ~Entity();
private:

    
};

#endif