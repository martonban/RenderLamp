#include "components/SphereMeshComponent.hpp"

SphereMeshComponent::SphereMeshComponent(Vector3 pos, float r) : mPos{pos}, mRadius{r} {}

void SphereMeshComponent::Start() {
    // Initialization code here
}

void SphereMeshComponent::LogicUpdate() {
    // Logic update code here
}

void SphereMeshComponent::RenderUpdate() {
    DrawSphere(mPos, mRadius, RED);
}