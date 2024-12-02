#include "Entity.h"

// Constructures
Entity::Entity():
    transform(
        Transform {
            Vector3 { 0, 0, 0 },
            Vector3 { 0, 0, 0 },
            Vector3 { 1, 1, 1 }
        }
    )
{}

Entity::Entity(Transform transform) : transform(transform) {}


// Manage Components
void Entity::AddNewComponent(Component component) {
    component_vector.push_back(component);
}


// ECS
void Entity::Start() {
    for (std::vector<Component>::size_type i = 0; i < component_vector.size(); i++) {
        component_vector[i].Start();
    }
}

void Entity::Update() {
    for (std::vector<Component>::size_type i = 0; i < component_vector.size(); i++) {
        component_vector[i].Update();
    }
}

void Entity::Destroy() {
    for (std::vector<Component>::size_type i = 0; i < component_vector.size(); i++) {
        component_vector[i].Destroy();
    }
}

// Getters
Transform Entity::GetTransform() { return transform; }