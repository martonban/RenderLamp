#ifndef RAY_INTERSECTION_KERNEL_HPP
#define RAY_INTERSECTION_KERNEL_HPP

#include "scene/Scene.hpp"
#include "scene/primitives/Geometry.hpp"
#include "scene/primitives/Sphere.hpp"
#include "scene/primitives/Mesh.hpp"
#include "utils/Ray.hpp"
#include "utils/HitRecord.hpp"
#include "utils/Interval.hpp"

namespace RenderLamp::PowderRenderer {
    inline void RayIntersection(Ray& ray, HitRecord& hitRecord, std::shared_ptr<Scene> scene) {
        Interval ray_t(0.001, std::numeric_limits<double>::infinity());
        hitRecord.hit = scene->Hit(ray, ray_t, hitRecord);
    }
}

#endif