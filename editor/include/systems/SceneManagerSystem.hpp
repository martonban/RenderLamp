#ifndef SCENE_MANAGER_SYSTEM_HPP
#define SCENE_MANAGER_SYSTEM_HPP

#include <filesystem>
#include <memory>
#include <map>
#include <cstdint>

#include "Arca.hpp"

#include "ecs/Entity.hpp"

class SceneManagerSystem {
public:
    // Handle Scene
    SceneManagerSystem();
    void SaveProject(const std::string& name, const std::filesystem::path& path);
    void LoadProject();
    // Handle Entites
    void AddEntity(const Entity& newEntity);
    void RemoveEntity(const uint64_t& id);
    std::shared_ptr<Entity> GetEntity(const uint64_t& id);
private:
    void AddDefaultScene();
    uint64_t currentID = 0;
    std::filesystem::path mPath;
    std::map<uint64_t, std::shared_ptr<Entity>> mEntities;
};

#endif