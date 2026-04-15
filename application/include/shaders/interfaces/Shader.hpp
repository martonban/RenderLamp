#ifndef SHADER_HPP
#define SHADER_HPP

#include <glm/vec3.hpp>

class Shader {
    virtual glm::dvec3 GetDirection(const glm::dvec3& normal) = 0;
};

#endif 