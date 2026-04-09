#ifndef INTERVAL_HPP
#define INTERVAL_HPP

#include <limits>

// Disclaimer: This class is based on the Interval class from "Ray Tracing in One Weekend"
// Source: https://raytracing.github.io/books/RayTracingInOneWeekend.html (Chapter 6.8)

class Interval {
    public:
        double min, max;

        Interval(): min(+std::numeric_limits<double>::infinity()), max(-std::numeric_limits<double>::infinity()) {}
        Interval(double min, double max) : min(min), max(max) {}

        double size() const {
            return max - min;
        }

        bool contains(double x) const {
            return min <= x && x <= max;
        }

        bool surrounds(double x) const {
            return min < x && x < max;
        }

        static const Interval empty, universe;
};

const Interval Interval::empty = Interval(+std::numeric_limits<double>::infinity(), -std::numeric_limits<double>::infinity());
const Interval Interval::universe = Interval(-std::numeric_limits<double>::infinity(), +std::numeric_limits<double>::infinity());

#endif