#include "components/SphereRenderComponent.hpp"

SphereRenderComponent::SphereRenderComponent(const Vector3& pos, const float& radius, const uint64_t& id) {
    mPos = pos;
    mRadius = radius;
    mId = id;
} 

SphereRenderComponent::SphereRenderComponent(const nlohmann::json& jsonObject) {
    
}


void SphereRenderComponent::Start() {
    mColor = RED;
}

void SphereRenderComponent::Tick() {
    DrawSphere(mPos, mRadius, mColor);
}

nlohmann::json SphereRenderComponent::ToSceneJson(){
    nlohmann::json root = nlohmann::json::object();
    nlohmann::json json;

    json["ComponentType"] = mComponenetType;

    json["Position"] = {
        {"x", mPos.x},
        {"y", mPos.y},
        {"z", mPos.z}
    };

    json["Radius"] = mRadius;

    root[std::to_string(mId)] = std::move(json);
    return root;
}

nlohmann::json SphereRenderComponent::ToRendererJson(){
    nlohmann::json root = nlohmann::json::object();
    nlohmann::json json;

    json["Position"] = {
        {"x", static_cast<double>(mPos.x)},
        {"y", static_cast<double>(mPos.y)},
        {"z", static_cast<double>(mPos.z)}
    };

    json["Radius"] = mRadius;

    root[std::to_string(mId)] = std::move(json);
    return root;
}


uint64_t SphereRenderComponent::GetID() {
    return mId;
}