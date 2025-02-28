#ifndef ENTITY_HPP
#define ENTITY_HPP

#include <iostream>
#include <vector>
#include <memory>

#include "Transform3D.hpp"
#include "Component.hpp"

class Entity {
    public:
        // Constractors
        Entity();
        Entity(Transform3D trans);

        // Manage Components
        void AddNewComponent(Component* component);
        //void RemoveComponent(Component component);


        // TODO: Rule of Five 

        // ECS
        void Start();
        void Update();
        void Destroy();

        // Get Transform
        Transform3D GetTransform();


    private:
        Transform3D transform;
        std::vector<Component*> component_vector;
};

#endif