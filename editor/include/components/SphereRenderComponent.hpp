#ifndef SPHERE_RENDER_COMPONENT_HPP
#define SPHERE_RENDER_COMPONENT_HPP

#include "raylib.h"

#include "ecs/Component.hpp"
#include <iostream>

class SphereRenderComponent : public Component {
    public:
        SphereRenderComponent(const Vector3& pos, const float& radius, const int& id);
        SphereRenderComponent(const int& id, const nlohmann::json& jsonObject);
        ~SphereRenderComponent() override = default;
        void Start() override;
        void Tick() override;
        int GetID() override;
        nlohmann::json ToSceneJson() override;
        nlohmann::json ToRendererJson() override;
    private:
        int mId;
        const std::string mComponenetType = "SphereRender";
        Vector3 mPos;
        float mRadius;
        Color mColor;
};

#endif