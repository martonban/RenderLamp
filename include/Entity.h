#ifndef ENTITY_H
#define ENTITY_H

#include <iostream>
#include <vector>

#include "Transform.h"
#include "Component.h"

class Entity {
    public:
        // Constractors
        Entity();
        Entity(Transform transform);

        // Manage Components
        void AddNewComponent(Component component);
        void RemoveComponent(Component component);

        // ECS
        void Start();
        void Update();
        void Destory();

        // Get Transform
        Transform GetTransform();


    private:
        Transform transform;
        std::vector<Component> component_map;
};

#endif