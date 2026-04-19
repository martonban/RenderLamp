#ifndef SHADER_HPP
#define SHADER_HPP

#include <glm/vec3.hpp>

class Shader {
    virtual glm::dvec3 BounceDirection(const Material& material, const glm::dvec3& normal) = 0;
    virtual glm::dvec3 BounceDirection(const glm::dvec3& normal) = 0;
    virtual Color GetColorContribution(const Material& material) = 0;
};

#endif 