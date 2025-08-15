#include "ArcaInstance.hpp"

bool ArcaInstance::IsFileExists(const std::string& fullFilePath) {
    return mArcaIO.IsFileExists(fullFilePath);
}

 bool ArcaInstance::CreateFolder(const std::string& path, const std::string& folderName) {
    return mArcaIO.CreateFolder(path, folderName);
 }