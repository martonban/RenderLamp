#ifndef DIFFUSE_SHADER_HPP
#define DIFFUSE_SHADER_HPP

#include "shaders/Shader.hpp"


class DiffuseShader : public Shader {
    public:
        inline void ExecuteShader(Ray& ray, HitRecord& hitRecord, glm::ivec3& color);
};

#endif