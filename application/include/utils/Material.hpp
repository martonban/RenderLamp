#ifndef MATERIAL_HPP
#define MATERIAL_HPP

#include <glm/vec3.hpp>
#include "shaders/ShaderType.hpp"

struct Material {
    ShaderType shaderType;
    glm::ivec3 albedo;
    float roughness = 0.0;
    float metalic = 0.0;
};

#endif