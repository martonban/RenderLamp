#ifndef ENTITY_HPP
#define ENTITY_HPP

#include <memory>
#include <vector>
#include <cstdint>
#include <functional>

#include "raylib.h"

#include "components/Transform3D.hpp"
#include "systems/scene/models/Component.hpp"

#include "components/SphereRenderComponent.hpp"


class Entity {
    public:
        Entity(const uint64_t& id, const Transform3D& transform);
        Entity(const nlohmann::json& entityJson);
        ~Entity();

        
        void Start();
        void Tick();
        void Destroy();

        
        void AddComponent(std::unique_ptr<Component> newComponent);

        template<typename T>
        T* GetComponent();

        template<typename T>
        T* GetComponent(const uint64_t& id);
        

        nlohmann::json Serializer();
        void Deserializer(const nlohmann::json& entityJson);
    
        uint64_t GetId();
        Transform3D& GetTransform();

    private:
        uint64_t mId;
        Transform3D mTransform;
        std::vector<std::unique_ptr<Component>> mComponenets;

        std::unique_ptr<Component> ComponentBuilder(const std::string type, const nlohmann::json& data);
        
};

#endif