#ifndef RANDOM_HPP
#define RANDOM_HPP

#include <random>
#include <glm/vec2.hpp>

namespace RenderLamp::Random {
    inline double RandomDouble(double min = 0.0, double max = 1.0) {
        static std::mt19937 gen(std::random_device{}());
        std::uniform_real_distribution<double> dist(min, max);
        return min + dist(gen) * (max - min);
    }

    inline glm::dvec2 SampleSquare() {
        return glm::dvec2(RandomDouble() - 0.5, RandomDouble() - 0.5);
    }

}



#endif