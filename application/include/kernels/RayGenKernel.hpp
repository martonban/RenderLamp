#ifndef RAY_GEN_KERNEL_HPP
#define RAY_GEN_KERNEL_HPP

#include "utils/Ray.hpp"
#include "utils/Random.hpp"
#include "scene/utils/Camera.hpp"
#include "session/SessionUtils.hpp"


namespace RenderLamp::PowderRenderer {
    inline void RayGenerationFromCamera(Ray& ray, const int& i, const int& j, std::shared_ptr<RenderLamp::Camera> camera) {
        glm::dvec2 offset = RenderLamp::Random::SampleSquare();

        glm::dvec3 pixelSample = camera->startPixelCoord 
            + (double(i) + offset.x) * camera->pixelDeltaU 
            + (double(j) + offset.y) * camera->pixelDeltaV;

        ray = Ray(camera->wordPos, glm::normalize(pixelSample - camera->wordPos));
    }
}

#endif