#ifndef GEOMETRY_HPP
#define GEOMETRY_HPP

#include "utils/Ray.hpp"
#include "utils/HitRecord.hpp"
#include "utils/Interval.hpp"

class Geometry {
    public:
        virtual bool Hit(Ray& r, Interval ray_t, HitRecord& hitRecord) = 0;
};

#endif 