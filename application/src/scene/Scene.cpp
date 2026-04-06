#include "scene/Scene.hpp"

Scene::Scene() {}

void Scene::AddGeometryToTheScene(std::shared_ptr<Geometry> geometryPtr) {
    mGeometriries.push_back(geometryPtr);
}

bool Scene::Hit(Ray& r, HitRecord& h) {
    for(auto &geometry : mGeometriries) {
        if(geometry -> Hit(r, h)) {
            return true;
        }
    }
    return false;
}