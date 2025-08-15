#include "ArcaIO.hpp"

bool ArcaIO::IsFileExists(const std::string& fullFilePath) {
    return std::filesystem::exists(fullFilePath) && std::filesystem::is_regular_file(fullFilePath);
}


bool ArcaIO::CreateFolder(const std::string& path, const std::string& name) {
    std::string fullPath = path + "/" + name;
    try {
        if (std::filesystem::exists(fullPath)) {
            std::cerr << "Warning: Directory already exists at path: " << fullPath << std::endl;
            return true;
        }
    
        if (!std::filesystem::create_directory(fullPath)) {
            std::cerr << "Error: Failed to create directory at path: " << fullPath << std::endl;
            return false;
        }
    } catch (const std::filesystem::filesystem_error& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
}