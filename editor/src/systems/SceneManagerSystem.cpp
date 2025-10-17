#include "systems/SceneManagerSystem.hpp"

SceneManagerSystem::SceneManagerSystem() {
    AddDefaultScene();
}

void SceneManagerSystem::SaveProject(const std::string& name, const std::filesystem::path& path) {
    Arca::CreateModule(path, name);
    mPath = path;
}

void SceneManagerSystem::LoadProject() {
    mEntities.clear();
}

void SceneManagerSystem::AddEntity(const Entity& newEntity) {
    mEntities[currentID] = std::make_shared<Entity>(newEntity);
    currentID++;
}

void SceneManagerSystem::RemoveEntity(const uint64_t& id) {
    mEntities.erase(id);
}

std::shared_ptr<Entity> SceneManagerSystem::GetEntity(const uint64_t& id) {
    return mEntities[id];
}


void SceneManagerSystem::AddDefaultScene() {}


