#ifndef GEOMETRY_HPP
#define GEOMETRY_HPP

#include "utils/Ray.hpp"
#include "utils/HitRecord.hpp"

class Geometry {
    public:
        virtual bool hit(const Ray& r, double tmin, double tmax, HitRecord& hitRecord) = 0;
};

#endif 