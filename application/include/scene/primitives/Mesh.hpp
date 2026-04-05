#ifndef MESH_HPP
#define MESH_HPP

#include <cmath>
#include <glm/vec3.hpp>
#include <glm/glm.hpp>

#include "scene/primitives/Geometry.hpp"
#include "scene/primitives/Triangle.hpp"
#include "utils/ModelLoader.hpp"


class Mesh : public Geometry {
    public:
        Mesh(const glm::dvec3& pos, const glm::dvec3& rot, const glm::dvec3& scale, const std::filesystem::path& path) {
            wordPos = pos;
            worldRot = rot;
            wordScale = scale;
            modelPath = path;

            // Load Verteces
            mTriangles = RenderLamp::ModelLoader::LoadPrimitiveObjFile(path);
            ScaleDown(4.0);
            MoveToOrigin();

            // Transform World space

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

        // AI TEST CODE
        void ScaleDown(double factor) {
            glm::dvec3 center(0.0);
            size_t vertexCount = 0;
            for (const auto& tr : mTriangles) {
                center += tr.v0 + tr.v1 + tr.v2;
                vertexCount += 3;
            }
            if (vertexCount > 0) {
                center /= static_cast<double>(vertexCount);
            }

            double scale = 1.0 / factor;
            for (auto& tr : mTriangles) {
                tr.v0 = center + (tr.v0 - center) * scale;
                tr.v1 = center + (tr.v1 - center) * scale;
                tr.v2 = center + (tr.v2 - center) * scale;
            }
        }

        // AI TEST CODE
        void MoveToOrigin() {
            glm::dvec3 center(0.0);
            size_t vertexCount = 0;
            for (const auto& tr : mTriangles) {
                center += tr.v0 + tr.v1 + tr.v2;
                vertexCount += 3;
            }
            if (vertexCount > 0) {
                center /= static_cast<double>(vertexCount);
            }

            for (auto& tr : mTriangles) {
                tr.v0 -= center;
                tr.v1 -= center;
                tr.v2 -= center;
            }
        }


    glm::dvec3 wordPos;
    glm::dvec3 worldRot;
    glm::dvec3 wordScale;

    std::filesystem::path modelPath;

    std::vector<Triangle> mTriangles;    
};

#endif