#include "Entity.hpp"

Entity::Entity(Transform3D trans):transform(trans) {}

// Manage Components
void Entity::AddNewComponent(const std::shared_ptr<Component>& component) {
    component_vector.push_back(component);
}

// ECS
void Entity::Start() {
    for (std::vector<std::shared_ptr<Component>>::size_type i = 0; i < component_vector.size(); i++) {
        component_vector[i]->Start();
    }
}

void Entity::Update() {
    for (std::vector<std::shared_ptr<Component>>::size_type i = 0; i < component_vector.size(); i++) {
        component_vector[i]->Update();
    }
}

void Entity::Destroy() {
    for (std::vector<std::shared_ptr<Component>>::size_type i = 0; i < component_vector.size(); i++) {
        component_vector[i]->Destroy();
    }
}

// Getters
Transform3D Entity::GetTransform() { return transform; }