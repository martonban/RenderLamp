#ifndef MODEL_LOADER_HPP
#define MODEL_LOADER_HPP

#include <filesystem>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <stdexcept>

#include "scene/primitives/Geometry.hpp"
#include "scene/primitives/Triangle.hpp"

namespace RenderLamp::ModelLoader {

    struct FaceVertex {
        int vi = -1;
        int ti = -1;
        int ni = -1;
    };

    inline FaceVertex ParseFaceVertex(const std::string& token, int vertexCount, int texCoordCount, int normalCount) {
        FaceVertex fv;
        std::istringstream ss(token);
        std::string part;

        // vertecies
        std::getline(ss, part, '/');
        if (!part.empty()) {
            fv.vi = std::stoi(part);
            if (fv.vi < 0) fv.vi = vertexCount + fv.vi + 1;
            fv.vi -= 1;
        }

        // texture coords
        if (std::getline(ss, part, '/')) {
            if (!part.empty()) {
                fv.ti = std::stoi(part);
                if (fv.ti < 0) fv.ti = texCoordCount + fv.ti + 1;
                fv.ti -= 1;
            }

            // normals
            if (std::getline(ss, part, '/')) {
                if (!part.empty()) {
                    fv.ni = std::stoi(part);
                    if (fv.ni < 0) fv.ni = normalCount + fv.ni + 1;
                    fv.ni -= 1;
                }
            }
        }

        return fv;
    }

    inline std::vector<Triangle> LoadPrimitiveObjFile(const std::filesystem::path& path) {
        std::vector<Triangle> result;
        std::vector<glm::dvec3> vertices;
        std::vector<glm::dvec3> normals;
        std::vector<glm::dvec3> texCoords;

        std::ifstream objFile(path);
        if (!objFile.is_open()) {
            std::cerr << "Failed to open OBJ file" << std::endl;
        }

        std::string line;
        while (std::getline(objFile, line)) {
            std::istringstream stringStream(line);
            std::string prefix;
            stringStream >> prefix;

            if (prefix == "v") {
                double x, y, z;
                stringStream >> x >> y >> z;
                vertices.emplace_back(x, y, z);
            } else if (prefix == "vn") {
                double x, y, z;
                stringStream >> x >> y >> z;
                normals.emplace_back(x, y, z);
            } else if (prefix == "vt") {
                double u, v, w = 0.0;
                stringStream >> u >> v;
                if (stringStream >> w) {}
                texCoords.emplace_back(u, v, w);
            } else if (prefix == "f") {
                std::vector<FaceVertex> faceVertices;
                std::string token;
                while (stringStream >> token) {
                    faceVertices.push_back(ParseFaceVertex(
                        token,
                        static_cast<int>(vertices.size()),
                        static_cast<int>(texCoords.size()),
                        static_cast<int>(normals.size())
                    ));
                }

                for (size_t i = 1; i + 1 < faceVertices.size(); ++i) {
                    Triangle tri{};
                    const auto& fv0 = faceVertices[0];
                    const auto& fv1 = faceVertices[i];
                    const auto& fv2 = faceVertices[i + 1];

                    tri.v0 = vertices[fv0.vi];
                    tri.v1 = vertices[fv1.vi];
                    tri.v2 = vertices[fv2.vi];

                    if (fv0.ni >= 0 && fv1.ni >= 0 && fv2.ni >= 0) {
                        tri.n0 = normals[fv0.ni];
                        tri.n1 = normals[fv1.ni];
                        tri.n2 = normals[fv2.ni];
                    }

                    if (fv0.ti >= 0 && fv1.ti >= 0 && fv2.ti >= 0) {
                        tri.t0 = texCoords[fv0.ti];
                        tri.t2 = texCoords[fv1.ti];
                        tri.t1 = texCoords[fv2.ti];
                    }

                    result.push_back(tri);
                }
            }
        }

        return result;
    }
}


#endif