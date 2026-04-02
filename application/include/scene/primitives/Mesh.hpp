#ifndef MESH_HPP
#define MESH_HPP

#include <cmath>
#include <glm/vec3.hpp>
#include <glm/glm.hpp>

#include "scene/primitives/Geometry.hpp"

struct Triangle {
    glm::dvec3 v0, v1, v2;
};

class Mesh : public Geometry {
    public:
        Mesh(const glm::dvec3& pos) {
            wordPos = pos;
            mTriangles.push_back(Triangle{
                glm::dvec3(0, 0, 0),
                glm::dvec3(1, 0, 0),
                glm::dvec3(0, 1, -0.75)
            });
            mTriangles.push_back(Triangle{
                glm::dvec3(0, 0, 0),
                glm::dvec3(0, 1, 0),
                glm::dvec3(0, 0, 1)
            });
            mTriangles.push_back(Triangle{
                glm::dvec3(1, 1, 0),
                glm::dvec3(2, 1, 0),
                glm::dvec3(1, 2, 0)
            });
            mTriangles.push_back(Triangle{
                glm::dvec3(-1, 0, 0),
                glm::dvec3(-2, 0, 0),
                glm::dvec3(-1, -1, 0)
            });
            mTriangles.push_back(Triangle{
                glm::dvec3(0, 0, -1),
                glm::dvec3(1, 0, -1),
                glm::dvec3(0, 1, -1)
            });
        }

        bool Hit(const Ray& r, const HitRecord& hitRecord) {
            for (const auto& tr : mTriangles) {
                glm::dvec3 e1 = tr.v1 - tr.v0;
                glm::dvec3 e2 = tr.v2 - tr.v0;
                glm::dvec3 t = r.orgin() - tr.v0;
                glm::dvec3 p = glm::cross(r.direction(), e2);
                glm::dvec3 q = glm::cross(t, e1);

                double denom = glm::dot(p, e1);
                if (fabs(denom) < 1e-8) continue;



                double invDenom = 1.0 / denom;
                double t2 = glm::dot(q, e2) * invDenom;
                double u = glm::dot(p, t) * invDenom;
                double v = glm::dot(q, r.direction()) * invDenom;

                if (u >= 0 && v >= 0 && u + v <= 1 && t2 > 0) {
                    return true;
                }
            }

            return false;
        }


    glm::dvec3 wordPos;
    std::vector<Triangle> mTriangles;    
};

#endif