#ifndef GEOMETRY_HPP
#define GEOMETRY_HPP

#include "utils/Ray.hpp"
#include "utils/HitRecord.hpp"

class Geometry {
    public:
        virtual bool Hit(const Ray& r, const HitRecord& hitRecord) = 0;
};

#endif 