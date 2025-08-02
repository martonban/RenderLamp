#include "ArcaInstance.hpp"

bool ArcaInstance::IsFileExists(const std::string& fullFilePath) {
    return mArcaIO.IsFileExists(fullFilePath);
}