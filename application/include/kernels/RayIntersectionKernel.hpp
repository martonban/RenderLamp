#ifndef RAY_INTERSECTION_KERNEL_HPP
#define RAY_INTERSECTION_KERNEL_HPP

#include "scene/Scene.hpp"
#include "scene/primitives/Geometry.hpp"
#include "scene/primitives/Sphere.hpp"
#include "scene/primitives/Mesh.hpp"
#include "utils/Ray.hpp"
#include "utils/HitRecord.hpp"

namespace RenderLamp::PowderRenderer {
    inline void RayIntersection(Ray& ray, HitRecord& hitRecord, std::shared_ptr<Scene> scene) {
        hitRecord.hit = scene->Hit(ray, hitRecord);
    }
}

#endif