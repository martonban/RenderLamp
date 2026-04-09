#include "scene/Scene.hpp"

Scene::Scene() {}

void Scene::AddGeometryToTheScene(std::shared_ptr<Geometry> geometryPtr) {
    mGeometriries.push_back(geometryPtr);
}

bool Scene::Hit(Ray& r, Interval ray_t, HitRecord& h) {
    bool anyHit = false;
    for(auto &geometry : mGeometriries) {
        if(geometry->Hit(r, ray_t, h)) {
            ray_t.max = h.t;
            anyHit = true;
        }
    }
    return anyHit;
}