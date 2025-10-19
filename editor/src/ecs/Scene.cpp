#include "ecs/Scene.hpp"

Scene::Scene(const int& width, const int& height) {
    mRenderer = std::make_unique<RealTimeRenderingSystem>(width, height);
}

void Scene::Start() {
    mRenderer->RenderingAllocation();
}

void Scene::Update() {
    mRenderer->Render();
    mRenderer->DrawFramebuffer();
}

void Scene::Destroy() {
    mRenderer->DestroyRenderer();
}