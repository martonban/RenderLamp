#include "scene/Scene.hpp"

Scene::Scene() {}

void Scene::AddGeometryToTheScene(std::shared_ptr<Sphere> geometryPtr) {
    mGeometriries.push_back(geometryPtr);
}

bool Scene::Hit(const Ray& r, const HitRecord& h) {
    for(auto &geometry : mGeometriries) {
        if(geometry -> Hit(r, h)) {
            return true;
        }
    }
    return false;
}