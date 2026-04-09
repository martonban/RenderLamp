#ifndef SPHERE_HPP
#define SPHERE_HPP

#include <memory>

#include <glm/vec3.hpp>
#include <glm/geometric.hpp>

#include "scene/primitives/Geometry.hpp"
#include "utils/Material.hpp"


class Sphere : public Geometry {
    public:
        Sphere(const glm::dvec3& wordPos, const double& radius) {
            pos = wordPos;
            mRadius = radius;
            mMaterialInfo = Material {EMPTY_SHADER, glm::ivec3{0, 0, 0}, 0.0, 0.0};
        }

        bool Hit(Ray& r, Interval ray_t, HitRecord& hitRecord) {
            glm::dvec3 origin = pos - r.orgin();
            auto a = glm::dot(r.direction(), r.direction());
            auto h = glm::dot(r.direction(), origin);
            auto c = glm::dot(origin, origin) - mRadius * mRadius;
        
            auto discriminant = h * h - a * c;

            if(discriminant < 0) {
                return false;
            }

            auto sqrtd = sqrt(discriminant);
            auto root = (h - sqrtd) / a;
            if(!ray_t.surrounds(root)) {
                root = (h + sqrtd) / a;
                if(!ray_t.surrounds(root)) {
                    return false;
                }
            }

            hitRecord.t = root;
            hitRecord.hitPoint = r.at(root);
            hitRecord.normal = (hitRecord.hitPoint - pos) / mRadius;
            hitRecord.material = std::make_shared<Material>(mMaterialInfo);

            return true;
        }

        void AddMaterial(const Material& material) {
            mMaterialInfo = material;
        }

        void TransformPosition(const glm::dvec3& trs) {
            pos += trs;
        }

        void TransformScale(const glm::dvec3& scale) {
            mRadius *= glm::max(scale.x, glm::max(scale.y, scale.z));
        }

        glm::dvec3 pos;
        double mRadius;
        Material mMaterialInfo;
};

#endif 