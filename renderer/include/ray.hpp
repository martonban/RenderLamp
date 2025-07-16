//------------------------------------------------------------------------------------------------
//                                       Buzz Renderer - Ray
//                                       Márton Bán (C) 2025
//	
//  This class is the same class what you can read in the Ray Tracing In On Weekend series.
//  To be fair at this level there is no difference :D
//------------------------------------------------------------------------------------------------

#ifndef RAY_HPP
#define RAY_HPP

#include <glm/vec3.hpp>

class ray {
public:
        ray() {};
        ray(const glm::dvec3& origin, const glm::dvec3& dir) : mOrigin(origin), mDir(dir)  {}

        const glm::dvec3& orgin() const { return mOrigin; }
        const glm::dvec3& direction() const { return mDir; }

        // P(t) = A + B(t)
        glm::dvec3 at(double t) {
                return mOrigin + mDir * t;
        }

private:
        glm::dvec3 mOrigin;
        glm::dvec3 mDir;
};

#endif