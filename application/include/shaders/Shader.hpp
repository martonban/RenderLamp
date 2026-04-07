#ifndef SHADER_HPP
#define SHADER_HPP

#include <glm/vec3.hpp>
#include "utils/Ray.hpp"
#include "utils/HitRecord.hpp"



class Shader {
    virtual void ExecuteShader(Ray& ray, HitRecord& hitRecord, glm::ivec3& color) = 0;
};


#endif 