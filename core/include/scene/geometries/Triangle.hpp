#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP

#include <glm/vec3.hpp>

struct Triangle {
    glm::dvec3 v0, v1, v2;
    glm::dvec3 n0, n1, n2;
    glm::dvec3 t0, t1, t2;
};

#endif