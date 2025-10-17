#ifndef ENTITY_HPP
#define ENTITY_HPP

#include <memory>
#include <vector>
#include <cstdint>

#include "Component.hpp"

class Entity {
public:
    Entity();
    ~Entity();
private:
    std::vector<std::shared_ptr<Component>> mComponentList;
};

#endif