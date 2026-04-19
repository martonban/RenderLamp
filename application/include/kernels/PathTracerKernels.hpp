#ifndef PATH_TRACER_KERNEL_HPP
#define PATH_TRACER_KERNEL_HPP

#include "session/SessionUtils.hpp"
#include "utils/HitRecord.hpp"
#include "kernels/ShadingKernel.hpp"
#include "utils/Ray.hpp"
#include "utils/Color.hpp"
#include "utils/Interval.hpp"
#include "scene/Scene.hpp"
#include "scene/lights/PointLight.hpp"


namespace RenderLamp::PowderRenderer {

    inline void DirectLightCalulation(HitRecord& hitRecord, std::shared_ptr<Scene> scene, Color& color);
    inline void IndirectLightCalculation(HitRecord& hitRecord, std::shared_ptr<Scene> scene, Color& color, int depth);

    inline void StartPathTracingKernel(Ray& ray, HitRecord& hitRecord, Color& color, std::shared_ptr<Scene> scene, const RenderLamp::SessionSettings& settings) {
        if(!hitRecord.hit) {
            RenderLamp::PowderRenderer::CalculateSkyboxColor(ray, color);
            return;
        }
        
        if(hitRecord.material && hitRecord.material->shaderType == DIFFUSE_SHADER) {
            color = Color(
                hitRecord.material->albedo.r / 255.0,
                hitRecord.material->albedo.g / 255.0,
                hitRecord.material->albedo.b / 255.0
            );
        } else {
            color = Color(0.8, 0.8, 0.8);
        }

        DirectLightCalulation(hitRecord, scene, color);
        IndirectLightCalculation(hitRecord, scene, color, settings.maxDepth);

    }

    inline void DirectLightCalulation(HitRecord& hitRecord, std::shared_ptr<Scene> scene, Color& color) {
        Color totalLight(0.0, 0.0, 0.0);
        constexpr double shadowOriginBias = 5e-3;
        for(auto l : scene->mLights) {
            glm::dvec3 originOffset = hitRecord.hitPoint + hitRecord.normal * shadowOriginBias;
            glm::dvec3 toLight = l->worldPos - originOffset;
            double lightDist = glm::length(toLight);
            glm::dvec3 dir = toLight / lightDist;
            Ray r = Ray(originOffset, dir);
            HitRecord tmpHitRecord;

            // Only test for occluders between surface and light
            Interval shadowInterval(1e-4, lightDist);
            tmpHitRecord.hit = scene->Hit(r, shadowInterval, tmpHitRecord);
        
            if(!tmpHitRecord.hit) {
                totalLight += RenderLamp::PowderRenderer::EvaluatePointLightContribution(r, hitRecord, l);
            }
        
        }
        color *= totalLight;
    }
    
    inline void IndirectLightCalculation(HitRecord& hitRecord, std::shared_ptr<Scene> scene, Color& color, int depth) {
        if(depth <= 1) return;

        constexpr double bounceOriginBias = 5e-3;
        Color indirectLight(0.0, 0.0, 0.0);
        Color throughput(1.0, 1.0, 1.0);
        HitRecord currentHit = hitRecord;

        for(int i = 1; i < depth; i++) {
            if(!currentHit.material) break;

            Color currentAlbedo(0.8, 0.8, 0.8);
            if(currentHit.material->shaderType == DIFFUSE_SHADER) {
                currentAlbedo = Color(
                    currentHit.material->albedo.r / 255.0,
                    currentHit.material->albedo.g / 255.0,
                    currentHit.material->albedo.b / 255.0
                );
            }
            throughput *= currentAlbedo;

            glm::dvec3 dir;

            switch (currentHit.material->shaderType) {
            case DIFFUSE_SHADER: {
                auto shader = std::make_unique<DiffuseShader>();
                dir = glm::normalize(shader->BounceDirection(currentHit.normal));
                break;
            }
            default:
                break;
            }

            glm::dvec3 originOffset = currentHit.hitPoint + currentHit.normal * bounceOriginBias;
            Ray childRay {originOffset, dir};
            HitRecord tmpHr;

            RenderLamp::PowderRenderer::RayIntersection(childRay, tmpHr, scene);

            if(!tmpHr.hit) {
                constexpr double envStrength = 0.2;
                Color skyColor;
                CalculateSkyboxColor(childRay, skyColor);
                indirectLight += throughput * skyColor * envStrength;
                break;
            }

            Color surfaceColor(0.8, 0.8, 0.8);
            if(tmpHr.material && tmpHr.material->shaderType == DIFFUSE_SHADER) {
                surfaceColor = Color(
                    tmpHr.material->albedo.r / 255.0,
                    tmpHr.material->albedo.g / 255.0,
                    tmpHr.material->albedo.b / 255.0
                );
            }

            Color bounceColor = surfaceColor;
            DirectLightCalulation(tmpHr, scene, bounceColor);
            indirectLight += throughput * bounceColor;

            currentHit = tmpHr;
        }

        color += indirectLight;
    }

}


#endif