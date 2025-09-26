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

        void StartArcaInstance(const std::string& applicationName);
        void CreateArcaInstance();
        void AddCreator(const std::string& creatorName);

        bool InstanceSerialize();
        bool InstanceDeserialize();

        nlohmann::json Save();
        void Load(const nlohmann::json& json);

        void ArcaTest();

        // ArcaModule Functions
        void CreateModule(const std::filesystem::path& moduleName);

        // ArcaIO Functions
        bool IsFileExists(const std::filesystem::path& fullFilePath);
        bool CreateFolder(const std::filesystem::path& path, const std::string& folderName);
    protected:
        ArcaInstance() = default;
    private:
        std::string mApplicationName = "Application";
        std::string mApplicationCreator = "Company Name Inc.";

        std::filesystem::path mInstanceFolderPath;
        std::filesystem::path mInstanceFilePath;

        nlohmann::json instanceJson;


        std::vector<std::filesystem::path> mModulePathContainer;
        
        ArcaIO mArcaIO;

        // Instace realated guard functions 
        ArcaInstance(const ArcaInstance&) = delete;
        ArcaInstance& operator=(const ArcaInstance&) = delete;
        
        // Arca Instance Builder 
        bool InstanceBuilder(const std::filesystem::path& path);
        
};

#endif