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

    inline void ShadowRayStage(HitRecord& hitRecord, std::shared_ptr<Scene> scene, Color& color);

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

        

        ShadowRayStage(hitRecord, scene, color);

        //SecondaryRayStage();


    }

    inline void ShadowRayStage(HitRecord& hitRecord, std::shared_ptr<Scene> scene, Color& color) {
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
        
        Color ambient(0.08, 0.08, 0.08);
        totalLight += ambient;


        color *= totalLight;
    } 


    //inline void SecondaryRayStage()

}


#endif