#ifndef SCENE_HPP
#define SCENE_HPP

#include <vector>
#include <memory>

#include "scene/primitives/Geometry.hpp"
#include "scene/primitives/Sphere.hpp"

class Scene {
    public:
        Scene();
        bool Hit(Ray& r, HitRecord& h);
        void AddGeometryToTheScene(std::shared_ptr<Geometry> geometryPtr);
    private:
        std::vector<std::shared_ptr<Geometry>> mGeometriries;
};

#endif