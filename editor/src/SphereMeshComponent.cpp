#include "SphereMeshComponent.hpp"

SphereMeshComponent::SphereMeshComponent(Vector3 pos, float r) : mPos{pos}, mRadius{r} {}

void SphereMeshComponent::Update() {
    DrawSphere(mPos, mRadius, RED);
}