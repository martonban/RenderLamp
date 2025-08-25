#ifndef ARCA_INSTANCE_HPP
#define ARCA_INSTANCE_HPP

#include <string>
#include <memory>
#include <filesystem>

#include "ArcaIO.hpp"
#include "ArcaPath.hpp"

class ArcaInstance {
    public:
        // Insntace Realted Funtions
        static ArcaInstance& GetInstance() {
            static ArcaInstance instance;
            return instance;
        }
        bool ArcaInstanceBuilder(const std::string& instanceName);
        void ApplicationDataSetup(const std::string& applicationName, const std::string& applicationCreator);

        // ArcaIO Functions
        bool IsFileExists(const std::filesystem::path& fullFilePath);
        bool CreateFolder(const std::filesystem::path& path, const std::string& folderName);
    protected:
        ArcaInstance() = default;
    private:
        std::string mApplicationName = "Application";
        std::string mApplicationCreator = "Company Name Inc.";
        std::map <std::string, ArcaPath> mPathMap;

        std::filesystem::path mInstanceFolderPath;
        std::filesystem::path mInstanceFilePath;

        ArcaIO mArcaIO;

        // Instace realated guard functions 
        ArcaInstance(const ArcaInstance&) = delete;
        ArcaInstance& operator=(const ArcaInstance&) = delete;
        
        // Arca Instance Builder 
        bool InstanceBuilder(const std::filesystem::path& path);
        
};

#endif