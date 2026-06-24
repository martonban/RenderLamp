#ifndef MESH_HPP
#define MESH_HPP

#include <cmath>
#include <glm/vec3.hpp>
#include <glm/glm.hpp>

#include "scene/geometries/Geometry.hpp"
#include "scene/geometries/Triangle.hpp"
#include "loaders/ModelLoader.hpp"
#include "scene/material/Material.hpp"


class Mesh : public Geometry {
    public:
        Mesh(const glm::dvec3& pos, const glm::dvec3& rot, const glm::dvec3& scale, const std::filesystem::path& path) {
            worldPos = pos;
            worldRot = rot;
            wordScale = scale;
            modelPath = path;
            mMaterialInfo = Material {EMPTY_SHADER, glm::ivec3{0, 0, 0}, 0.0, 0.0};


            // Load Verteces
            mTriangles = RenderLamp::ModelLoader::LoadPrimitiveObjFile(path);

            // Transform World space (SRT order: Scale -> Rotate -> Translate)
            TransformScale(wordScale);
            TransformRotation(worldRot);
            TransformPosition(worldPos);
        }

        void AddMaterial(const Material& material) {
            mMaterialInfo = material;
        }

        bool Hit(Ray& r, Interval ray_t, HitRecord& hitRecord) {
            bool anyHit = false;
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

                double w = 1.0 - u - v;

                if (u >= 0 && v >= 0 && u + v <= 1 && ray_t.surrounds(t2)) {
                    ray_t.max = t2;
                    hitRecord.t = t2;
                    hitRecord.hitPoint = r.at(t2);
                    hitRecord.normal = glm::normalize(w * tr.n0 + u * tr.n1 + v * tr.n2);
                    hitRecord.material = std::make_shared<Material>(mMaterialInfo);
                    anyHit = true;
                }
            }

            return anyHit;
        }

        void TransformPosition(const glm::dvec3& trs) {
            for (auto& tr : mTriangles) {
                tr.v0 += trs;
                tr.v1 += trs;
                tr.v2 += trs;
            }
        }

        void TransformScale(const glm::dvec3& trs) {
            glm::dvec3 invScale = 1.0 / trs;
            for (auto& tr : mTriangles) {
                tr.v0 *= trs;
                tr.v1 *= trs;
                tr.v2 *= trs;

                tr.n0 = glm::normalize(tr.n0 * invScale);
                tr.n1 = glm::normalize(tr.n1 * invScale);
                tr.n2 = glm::normalize(tr.n2 * invScale);
            }
        }

        void TransformRotation(const glm::dvec3& rot) {
            double cx = cos(rot.x), sx = sin(rot.x);
            double cy = cos(rot.y), sy = sin(rot.y);
            double cz = cos(rot.z), sz = sin(rot.z);

            // YXZ rotation matrix
            glm::dmat3 matrix(
                cy * cz + sy * sx * sz,  cx * sz, -sy * cz + cy * sx * sz,
                -cy * sz + sy * sx * cz, cx * cz, sy * sz + cy * sx * cz,
                sy * cx,                 -sx,     cy * cx
            );

            for (auto& tr : mTriangles) {
                tr.v0 = matrix * tr.v0;
                tr.v1 = matrix * tr.v1;
                tr.v2 = matrix * tr.v2;

                tr.n0 = matrix * tr.n0;
                tr.n1 = matrix * tr.n1;
                tr.n2 = matrix * tr.n2;
            }
        }


        glm::dvec3 worldPos;
        glm::dvec3 worldRot;
        glm::dvec3 wordScale;

        std::filesystem::path modelPath;

        std::vector<Triangle> mTriangles;
        Material mMaterialInfo;
};

#endif