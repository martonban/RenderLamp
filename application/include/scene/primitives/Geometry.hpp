#ifndef GEOMETRY_HPP
#define GEOMETRY_HPP

#include "utils/Ray.hpp"
#include "utils/HitRecord.hpp"

class Geometry {
    public:
        virtual bool Hit(Ray& r, HitRecord& hitRecord) = 0;
};

#endif 