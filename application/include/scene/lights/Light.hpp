#ifndef LIGHT_HPP
#define LIGHT_HPP

#include "utils/Ray.hpp"
#include "utils/Color.hpp"

class Light {
    virtual Color Radiance(Ray& r) = 0;
};

#endif