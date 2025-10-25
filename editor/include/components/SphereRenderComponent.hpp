#ifndef SPHERE_RENDER_COMPONENT_HPP
#define SPHERE_RENDER_COMPONENT_HPP

#include "raylib.h"
#include "raymath.h"

#include "ecs/Component.hpp"

class SphereRenderComponent : public Component {
    public:
        SphereRenderComponent(const Vector3& pos, const float& radius, const uint64_t& id);
        SphereRenderComponent(const nlohmann::json& jsonObject);
        ~SphereRenderComponent() override = default;
        void Start() override;
        void Tick() override;
        uint64_t GetID() override;
        nlohmann::json ToSceneJson() override;
        nlohmann::json ToRendererJson() override;
    private:
        uint64_t mId;
        const std::string mComponenetType = "SphereRender";
        Vector3 mPos;
        float mRadius;
        Color mColor;
};

#endif