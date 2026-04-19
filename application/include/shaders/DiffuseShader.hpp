#ifndef DIFFUSE_SHADER_HPP
#define DIFFUSE_SHADER_HPP

#include "shaders/interfaces/Shader.hpp"
#include "utils/HitRecord.hpp"
#include "utils/Random.hpp"
#include "utils/Color.hpp"
#include "scene/material/Material.hpp"

class DiffuseShader : public Shader {
    public:
        inline glm::dvec3 BounceDirection(const Material& material, const glm::dvec3& normal) override {
            return glm::normalize(normal + RenderLamp::Random::RandomUnitVector());
        }

        inline glm::dvec3 BounceDirection(const glm::dvec3& normal) override {
            return glm::normalize(normal + RenderLamp::Random::RandomUnitVector());
        }

        inline Color GetColorContribution(const Material& material) override {
            return Color(
                material.albedo.r / 255.0,
                material.albedo.g / 255.0,
                material.albedo.b / 255.0
            );
        }
};

#endif