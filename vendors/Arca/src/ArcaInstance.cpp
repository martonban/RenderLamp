#include "ArcaInstance.hpp"

bool ArcaInstance::CreateInstance(const std::string& instanceName) {
    std::string path = "././" + instanceName;
    std::string instanceFilePAth = path + "/" + instanceName + ".txt";
    


}

bool ArcaInstance::IsFileExists(const std::string& fullFilePath) {
    return mArcaIO.IsFileExists(fullFilePath);
}

 bool ArcaInstance::CreateFolder(const std::string& path, const std::string& folderName) {
    return mArcaIO.CreateFolder(path, folderName);
}
