#ifndef ARCA_INSTANCE_HPP
#define ARCA_INSTANCE_HPP

#include <string>
#include <memory>
#include <filesystem>

#include "ArcaIO.hpp"

class ArcaInstance {
    public:
        // Insntace Realted Funtions
        static ArcaInstance& GetInstance() {
            static ArcaInstance instance;
            return instance;
        }
        bool ArcaInstanceBuilder(const std::string& instanceName);

        // ArcaIO Functions
        bool IsFileExists(const std::filesystem::path& fullFilePath);
        bool CreateFolder(const std::filesystem::path& path, const std::string& folderName);
    protected:
        ArcaInstance() = default;
    private:
        ArcaIO mArcaIO;

        std::filesystem::path mInstanceFolderPath;
        std::filesystem::path mInstanceFilePath;

        // Instace realated guard functions 
        ArcaInstance(const ArcaInstance&) = delete;
        ArcaInstance& operator=(const ArcaInstance&) = delete;
        
        // Arca Instance Builder 
        bool InstanceBuilder(const std::filesystem::path& path);

};

#endif