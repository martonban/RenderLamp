#ifndef SHADING_KERNEL_HPP
#define SHADING_KERNEL_HPP

#include "utils/HitRecord.hpp"
#include "utils/Ray.hpp"
#include "utils/Color.hpp"
#include <glm/glm.hpp>

namespace RenderLamp::PowderRenderer {
    inline void ShadingKernel(HitRecord& hitRecord, Ray& ray, Color& color) {
        if(hitRecord.hit && hitRecord.material) {
            switch (hitRecord.material->shaderType) {
                case DIFFUSE_SHADER:
                    color = Color(
                        static_cast<double>(hitRecord.material->albedo.x) / 255.0,
                        static_cast<double>(hitRecord.material->albedo.y) / 255.0,
                        static_cast<double>(hitRecord.material->albedo.z) / 255.0
                    );
                    break;
                case EMPTY_SHADER:
                default:
                    color = Color(
                        (hitRecord.normal.x + 1.0) * 0.5,
                        (hitRecord.normal.y + 1.0) * 0.5,
                        (hitRecord.normal.z + 1.0) * 0.5
                    );
                    break;
            }
        } else if (hitRecord.hit) {
            color = Color(
                (hitRecord.normal.x + 1.0) * 0.5,
                (hitRecord.normal.y + 1.0) * 0.5,
                (hitRecord.normal.z + 1.0) * 0.5
            );
        } else {
            glm::dvec3 dir = glm::normalize(ray.direction());
            double t = 0.5 * (dir.y + 1.0);
            color = Color(
                (1.0 - t) * 1.0 + t * 0.5,
                (1.0 - t) * 1.0 + t * 0.7,
                (1.0 - t) * 1.0 + t * 1.0
            );
        }
    }
}

#endif 
