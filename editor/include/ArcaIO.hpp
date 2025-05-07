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

    // Fetch all strings from a CSV file
    void FetchCSVData(const std::string& filePath, std::vector<std::string>& returnVector) {
        std::ifstream file(filePath);
        if (!std::filesystem::exists(filePath)) {
            std::cerr << "Error: The file does not exist! \n";
            return;
        }
    
        std::string temp;

        if(std::getline(file, temp, ';')) {
            returnVector.push_back(temp);
        }

        file.close();
    }

    
};



#endif