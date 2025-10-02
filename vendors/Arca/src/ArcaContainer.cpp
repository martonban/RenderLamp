#include "ArcaContainer.hpp"

ArcaContainer::ArcaContainer(const std::filesystem::path& path, const std::string& fileName) {
    mPath = path / (fileName + ".json");
}

void ArcaContainer::AddPair(const std::string& key, const std::any& value) {
    mContainer[key] = value;
}

