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

bool ArcaInstance::InstanceDeserialize() {
    std::ifstream file(mInstanceFilePath);
    if(file.is_open()) {
        nlohmann::json instanceJson;
        file >> instanceJson;
        file.close();
        Load(instanceJson);
        return true;
    } else {
        std::cout << "Instance can't be deserialized" << std::endl;
        return false;
    }

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

void ArcaInstance::Load(const nlohmann::json& json) {
    if(json.contains("ApplicationName")) {
        mApplicationName = json["ApplicationName"];
    }

    if(json.contains("ApplicationCreator")) {
        mApplicationCreator = json["ApplicationCreator"];
    }

    if (json.contains("ModulePaths")) {
        mModulePathContainer.clear(); // Clear existing paths
        for (const auto& path : json["ModulePaths"]) {
            if (path.is_string()) {
                mModulePathContainer.push_back(std::filesystem::path(path.get<std::string>()));
            }
        }
    }
}

void ArcaInstance::ArcaTest() {
    std::cout << mApplicationName << std::endl;
    std::cout << mApplicationCreator << std::endl;
    for(const auto& path : mModulePathContainer) {
        std::cout << path << std::endl;
    }
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
