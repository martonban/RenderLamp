#ifndef COMPONENT_HPP
#define COMPONENT_HPP

#include <cstdint>
#include <nlohmann/json.hpp>


class Component {
    public:
        Component() = default;
        Component(const uint64_t& id, const nlohmann::json& jsonObject);
        virtual ~Component() = default;
        virtual void Start() = 0;
        virtual void Tick() = 0;
        virtual void Destroy() = 0;
        virtual nlohmann::json ToSceneJson() = 0;
        virtual nlohmann::json ToRendererJson() { return nlohmann::json::object(); };
        virtual uint64_t GetID() = 0;
};

#endif