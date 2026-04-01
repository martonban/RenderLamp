#ifndef HIT_RECORD_HPP
#define HIT_RECORD_HPP

#include <glm/vec3.hpp>

class HitRecord {
    public:
        glm::dvec3 p;
        glm::dvec3 normal;
        double t;
};

#endif