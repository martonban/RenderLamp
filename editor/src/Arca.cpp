#include "Arca.hpp"

// To create an Arca Instance you need the file
Arca::Arca(const std::string& applicationName) {
    // Setup Application Workspace
    CreateDirectory(GetAppPath(), applicationName);
}

void Arca::CreateDirectory(const std::string& path, const std::string& name) {
    arcaIO.CreateFolder(path, name);
}

// TODO: Make it better
std::string Arca::GetAppPath() {
    return "C:";
}