#ifndef RANDOM_HPP
#define RANDOM_HPP

#include <random>

inline double RandomDouble(double min = 0.0, double max = 0.0) {
    static std::mt19937 gen(std::random_device{}());
    std::uniform_real_distribution<double> dist(min, max);
    return dist(gen);
}

#endif