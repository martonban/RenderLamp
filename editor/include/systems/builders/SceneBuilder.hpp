#ifndef SCENE_BUILDER_HPP
#define SCENE_BUILDER_HPP

#include <filesystem>
#include <cstdint>
#include <map>

#include "Arca.hpp"
#include "ecs/Component.hpp"
#include "ecs/Entity.hpp"

class SceneBuilder {
    public:
        SceneBuilder(const std::string& projectName);
        void DeserializeComponents(std::map<uint64_t, std::shared_ptr<Component>>& mapRef);
        void DeserilaizeEntities(std::map<uint64_t, std::shared_ptr<Entity>>& mapRef);
};

#endif