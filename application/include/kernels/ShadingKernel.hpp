#ifndef SHADING_KERNEL_HPP
#define SHADING_KERNEL_HPP

#include <glm/glm.hpp>

#include "utils/HitRecord.hpp"
#include "utils/Ray.hpp"
#include "utils/Color.hpp"

#include "scene/lights/PointLight.hpp"

#include "shaders/DiffuseShader.hpp"


namespace RenderLamp::PowderRenderer {
    inline void CalculateSkyboxColor(Ray& ray, Color& color) {
        glm::dvec3 dir = glm::normalize(ray.direction());
        double t = 0.5 * (dir.y + 1.0);
        color = Color(
            (1.0 - t) * 1.0 + t * 0.5,
            (1.0 - t) * 1.0 + t * 0.7,
            (1.0 - t) * 1.0 + t * 1.0
        ); 
    }

    inline Color EvaluatePointLightContribution(const Ray& ray, const HitRecord& hr, std::shared_ptr<PointLight> light) {
        glm::dvec3 lightDir = glm::normalize(light->worldPos - hr.hitPoint);

        double cosTheta = glm::max(0.0,  glm::dot(hr.normal, lightDir));

        double dist = glm::length(light->worldPos - hr.hitPoint);
        double attenuation = 1.0f / (light->attenuation * dist * dist);

        return light->lightColor * light->intensity * attenuation * cosTheta;
    }


    inline void ShadingKernel(Ray& ray, HitRecord& hitRecord, Color& color) {
        if(hitRecord.hit && hitRecord.material) {
            switch (hitRecord.material->shaderType) {
                case DIFFUSE_SHADER: {
                    DiffuseShader shader;
                    auto dir = shader.GetDirection(hitRecord.normal);
                    color = shader.GetColor(hitRecord.material, dir);
                    break;
                }
                case EMPTY_SHADER: {
                    color = Color(
                        (hitRecord.normal.x + 1.0) * 0.5,
                        (hitRecord.normal.y + 1.0) * 0.5,
                        (hitRecord.normal.z + 1.0) * 0.5
                    );
                    break;
                }
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
