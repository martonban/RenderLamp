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

    inline std::vector<Triangle> LoadPrimitiveObjFile(const std::filesystem::path& path) {
        std::vector<Triangle> result;
        std::vector<glm::dvec3> vertices;

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
            } else if (prefix == "f") {
                std::vector<int> faceIndices;
                std::string token;
                while (stringStream >> token) {
                    int vertexIndex = std::stoi(token.substr(0, token.find('/')));
                    if (vertexIndex < 0) {
                        vertexIndex = static_cast<int>(vertices.size()) + vertexIndex + 1;
                    }
                    faceIndices.push_back(vertexIndex - 1);
                }

                for (size_t i = 1; i + 1 < faceIndices.size(); ++i) {
                    Triangle tri;
                    tri.v0 = vertices[faceIndices[0]];
                    tri.v1 = vertices[faceIndices[i]];
                    tri.v2 = vertices[faceIndices[i + 1]];
                    result.push_back(tri);
                }
            }
        }

        return result;
    }
}


#endif