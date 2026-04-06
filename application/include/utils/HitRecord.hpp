#ifndef HIT_RECORD_HPP
#define HIT_RECORD_HPP

#include <glm/vec3.hpp>
#include <limits>

class HitRecord {
    public:
        bool hit = false;
        double t = std::numeric_limits<double>::max();;    
        glm::dvec3 hitPoint;
        glm::dvec3 normal;
};

#endif