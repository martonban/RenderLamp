#include "ArcaInstance.hpp"

bool ArcaInstance::ArcaInstanceBuilder(const std::string& instanceName) {
    mInstanceFolderPath = std::filesystem::path("./");
    mInstanceFilePath = mInstanceFolderPath / instanceName / (instanceName + ".json");

    if(CreateFolder(mInstanceFolderPath, instanceName) && InstanceBuilder(mInstanceFilePath)) {
        return true;
    } else {
        return false;
    }
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
