#ifndef SPHERE_HPP
#define SPHERE_HPP

#include <glm/vec3.hpp>
#include <glm/geometric.hpp>

#include "scene/primitives/Geometry.hpp"


class Sphere : public Geometry {
    public:
        Sphere(const glm::dvec3& wordPos, const double& radius) {
            pos = wordPos;
            mRadius = radius;
        }

        bool Hit(const Ray& r, const HitRecord& hitRecord) {
            glm::dvec3 origin = pos - r.orgin();
            auto a = glm::dot(r.direction(), r.direction());
            auto h = glm::dot(r.direction(), origin);
            auto c = glm::dot(origin, origin) - mRadius * mRadius;
        
            auto discriminant = h * h - a * c;

            if(discriminant < 0) {
                return false;
            }

            return true;
        }

        glm::dvec3 pos;
        double mRadius;
};

#endif 