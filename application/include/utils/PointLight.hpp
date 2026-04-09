#ifndef POINT_LIGHT_HPP
#define POINT_LIGHT_HPP

#include <glm/vec3.hpp>

struct PointLight {
    glm::dvec3 worldPos;
    glm::dvec3 LightColor;
    double intensity;
    double lightRange;
    double attenuation;
};

#endif