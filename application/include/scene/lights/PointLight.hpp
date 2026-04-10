#ifndef POINT_LIGHT_HPP
#define POINT_LIGHT_HPP

#include <glm/vec3.hpp>

#include "scene/lights/Light.hpp"

class PointLight : public Light{

    glm::dvec3 worldPos;
    glm::dvec3 LightColor;
    double intensity;
    double lightRange;
    double attenuation;


    Color Radiance(Ray& r);
};

#endif