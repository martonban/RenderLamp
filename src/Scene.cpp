#include "Scene.h"

Scene::Scene() {

} 

void Scene::Start() {
    for (std::vector<Entity>::size_type i = 0; i < entity_vector.size(); i++) {
        entity_vector[i].Start();
    }
}

void Scene::Tick() {
    for (std::vector<Entity>::size_type i = 0; i < entity_vector.size(); i++) {
        entity_vector[i].Update();
    }
}

void Scene::Destroy() {
    for (std::vector<Entity>::size_type i = 0; i < entity_vector.size(); i++) {
        entity_vector[i].Destroy();
    }
}