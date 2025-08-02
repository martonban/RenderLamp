//-----------------------------------------------------------------------------
//                              RenderLamp - ArcaIO
//
//  This class is responsible for file handleing.
//-----------------------------------------------------------------------------

#ifndef ARCA_IO_HPP
#define ARCA_IO_HPP

#include <iostream>
#include <fstream>
#include <filesystem>

#include <string>
#include <map>

#include <nlohmann/json.hpp>
using json = nlohmann::json;


class ArcaIO {
    public: 
    void CreateFolder(const std::string& path, const std::string& name) {
        std::string fullPath = path + "/" + name;
        try {
            if (std::filesystem::exists(fullPath)) {
                std::cerr << "Warning: Directory already exists at path: " << fullPath << std::endl;
                return;
            }
    
            if (!std::filesystem::create_directory(fullPath)) {
                std::cerr << "Error: Failed to create directory at path: " << fullPath << std::endl;
            }
        } catch (const std::filesystem::filesystem_error& e) {
            std::cerr << "Exception: " << e.what() << std::endl;
        }
    } 
};



#endif