#ifndef ENTITY_H
#define ENTITY_H

#include <iostream>
#include <vector>

#include "Transform3D.h"
#include "Component.h"

class Entity {
    public:
        // Constractors
        Entity();
        Entity(Transform3D trans);

        // Manage Components
        void AddNewComponent(Component component);
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
        std::vector<Component> component_vector;
};

#endif