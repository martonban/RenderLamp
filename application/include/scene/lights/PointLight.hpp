#ifndef POINT_LIGHT_HPP
#define POINT_LIGHT_HPP

#include <glm/vec3.hpp>

#include "scene/lights/Light.hpp"

class PointLight {
public: 
    PointLight(glm::dvec3 pos, glm::dvec3 color, double intens, double range, double atten)
        : worldPos(pos), lightColor(color), intensity(intens), lightRange(range), attenuation(atten) {}

    glm::dvec3 worldPos;
    glm::dvec3 lightColor;
    double intensity;
    double lightRange;
    double attenuation;

    glm::dvec3 GetWorldPos() {
        return worldPos;
    }
    
    glm::dvec3 GetLightColor() {
        return lightColor;
    }
    
    double GetIntensity() {
        return intensity;
    }
    
    double GetLightRange() {
        return lightRange;
    }
    
    double GetAttenuation() {
        return attenuation;
    }
    
    Color Radiance(Ray& r);
};

#endif