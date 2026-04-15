#ifndef SCENE_HPP
#define SCENE_HPP

#include <vector>
#include <memory>

#include "scene/geometries/Geometry.hpp"
#include "scene/geometries/Sphere.hpp"
#include "scene/lights/Light.hpp"
#include "scene/lights/PointLight.hpp"

class Scene {
    public:
        Scene();
        bool Hit(Ray& r, Interval ray_t, HitRecord& h);
        void AddGeometryToTheScene(std::shared_ptr<Geometry> geometryPtr);
        void AddLightToTheScene(std::shared_ptr<PointLight> lightPtr);

        std::vector<std::shared_ptr<PointLight>> mLights;
    private:
        std::vector<std::shared_ptr<Geometry>> mGeometriries;

};

#endif