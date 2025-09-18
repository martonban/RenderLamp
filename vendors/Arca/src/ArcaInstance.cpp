#include "ArcaInstance.hpp"

void ArcaInstance::StartArcaInstance(const std::string& applicationName) {
    mApplicationName = applicationName;
    mInstanceFolderPath = std::filesystem::path("./");
    mInstanceFilePath = mInstanceFolderPath / "ArcaFiles" / (applicationName + ".json");
}

void ArcaInstance::CreateArcaInstance() {
    // Directory has been created
    if(CreateFolder(mInstanceFolderPath, "ArcaFiles")) {
        std::cout << "Arca Instance directory has been created" << std::endl;
    } else {
        std::cout << "Arca Instance directory cannot able to create" << std::endl;
    }
}

void ArcaInstance::AddCreator(const std::string& creatorName) {
    mApplicationCreator = creatorName;
}


bool ArcaInstance::InstanceSerialize() {
    nlohmann::json instanceJson = Save();
    std::ofstream file(mInstanceFilePath);
    if (!file.is_open()) {
        return false;
    }
    file << instanceJson.dump(4);
    file.close();
    return true;
}

nlohmann::json ArcaInstance::Save() {
    nlohmann::json json;
    json["ApplicationName"] = mApplicationName;
    json["ApplicationCreator"] = mApplicationCreator;
    
    // Serialize module path container
    nlohmann::json modulePaths = nlohmann::json::array();
    for (const auto& path : mModulePathContainer) {
        modulePaths.push_back(path.string());
    }
    json["ModulePaths"] = modulePaths;

    return json;
}

void ArcaInstance::CreateModule(const std::filesystem::path& path) {
    mModulePathContainer.push_back(path);
}


bool ArcaInstance::IsFileExists(const std::filesystem::path& fullFilePath) {
    return mArcaIO.IsFileExists(fullFilePath);
}

bool ArcaInstance::CreateFolder(const std::filesystem::path& path, const std::string& folderName) {
    return mArcaIO.CreateFolder(path, folderName);
}

bool ArcaInstance::InstanceBuilder(const std::filesystem::path& path) {
    return true;
}
