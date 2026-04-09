#ifndef SHADING_KERNEL_HPP
#define SHADING_KERNEL_HPP

#include "utils/HitRecord.hpp"
#include "utils/Ray.hpp"
#include <glm/glm.hpp>

namespace RenderLamp::PowderRenderer {
    inline void ShadingKernel(HitRecord& hitRecord, Ray& ray, int& ir, int& ig, int& ib) {
        if(hitRecord.hit && hitRecord.material) {
            switch (hitRecord.material->shaderType) {
                case DIFFUSE_SHADER:
                    ir = hitRecord.material->albedo.x;
                    ig = hitRecord.material->albedo.y;
                    ib = hitRecord.material->albedo.z;
                    break;
                case EMPTY_SHADER:
                    ir = static_cast<int>((hitRecord.normal.x + 1.0) * 0.5 * 255.0);
                    ig = static_cast<int>((hitRecord.normal.y + 1.0) * 0.5 * 255.0);
                    ib = static_cast<int>((hitRecord.normal.z + 1.0) * 0.5 * 255.0);
                    break;
                default:
                    ir = static_cast<int>((hitRecord.normal.x + 1.0) * 0.5 * 255.0);
                    ig = static_cast<int>((hitRecord.normal.y + 1.0) * 0.5 * 255.0);
                    ib = static_cast<int>((hitRecord.normal.z + 1.0) * 0.5 * 255.0);
                    break;
            }   
           
        } else if (hitRecord.hit) {
            ir = static_cast<int>((hitRecord.normal.x + 1.0) * 0.5 * 255.0);
            ig = static_cast<int>((hitRecord.normal.y + 1.0) * 0.5 * 255.0);
            ib = static_cast<int>((hitRecord.normal.z + 1.0) * 0.5 * 255.0);
        } else {
            glm::dvec3 dir = glm::normalize(ray.direction());
            double t = 0.5 * (dir.y + 1.0);
            ir = static_cast<int>(255.999 * ((1.0 - t) * 1.0 + t * 0.5));
            ig = static_cast<int>(255.999 * ((1.0 - t) * 1.0 + t * 0.7));
            ib = static_cast<int>(255.999 * ((1.0 - t) * 1.0 + t * 1.0));
        }
    }
}

#endif 
