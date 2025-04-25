#include "Arca.hpp"

// To create an Arca Instance you need the file
Arca::Arca() {

}

void Arca::CreateDirectory(const std::string& path, const std::string& name) {
    arcaIO.CreateFolder(path, name);
}