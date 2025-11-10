#ifndef SPHERE_RENDER_COMPONENT_HPP
#define SPHERE_RENDER_COMPONENT_HPP

#include "raylib.h"

#include <iostream>
#include <memory>

#include "systems/scene/models/Component.hpp"
#include "systems/scene/models/Entity.hpp"
#include "components/Transform3D.hpp"

class SphereRenderComponent : public Component {
    public:
        SphereRenderComponent(const Vector3& pos, const float& radius, const uint64_t& id);
        SphereRenderComponent(const uint64_t& id, const nlohmann::json& jsonObject);
        ~SphereRenderComponent() override = default;
        void Start() override;
        void Tick() override;
        void Destroy() override;
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