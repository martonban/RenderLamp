#ifndef RAY_GEN_KERNEL_HPP
#define RAY_GEN_KERNEL_HPP

#include "utils/Ray.hpp"
#include "utils/Camera.hpp"
#include "session/SessionUtils.hpp"


namespace RenderLamp::PowderRenderer {
    inline void RayGenaration(Ray& ray, const int& i, const int& j, std::shared_ptr<RenderLamp::Camera> camera) {
        glm::dvec3 pixelSample = camera->startPixelCoord + double(i) * camera->pixelDeltaU + double(j) * camera->pixelDeltaV;
        ray = Ray(camera->wordPos, glm::normalize(pixelSample - camera->wordPos));
    }
}

#endif