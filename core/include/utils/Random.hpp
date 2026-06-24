#ifndef RANDOM_HPP
#define RANDOM_HPP

#include <random>
#include <glm/vec2.hpp>

namespace RenderLamp::Random {
    inline double RandomDouble(double min = 0.0, double max = 1.0) {
        static thread_local std::mt19937 gen(std::random_device{}());
        std::uniform_real_distribution<double> dist(min, max);
        return dist(gen);
    }

    inline glm::dvec2 SampleSquare() {
        return glm::dvec2(RandomDouble() - 0.5, RandomDouble() - 0.5);
    }

    inline glm::dvec3 SampleSphere(double min = 0.0, double max = 1.0) {
        return glm::vec3(RandomDouble(min, max), RandomDouble(min, max), RandomDouble(min, max));
    }

    inline glm::dvec3 RandomUnitVector() {
        while (true) {
            auto p = SampleSphere(-1,1);
            auto lensq = glm::dot(p, p);
            if (1e-160 < lensq && lensq <= 1) {
                return p / sqrt(lensq);
            }
        }
    }

    inline glm::dvec3 RandomOnHemisphere(const glm::dvec3& normal) {
        glm::dvec3 unitSphere = RandomUnitVector();
        if (dot(unitSphere, normal) > 0.0) {
            return unitSphere;
        } else {
            return -unitSphere;
        } 
    }
}

#endif