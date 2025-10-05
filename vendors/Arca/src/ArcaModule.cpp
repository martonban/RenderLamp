#include "ArcaModule.hpp"

ArcaModule::ArcaModule(const std::filesystem::path& path, const std::string& name) {
    mModuleName = name;

    // Create Folder for the module 
    if(io.CreateFolder(path, name)) {
        std::cout << "Everything is cool!" << std::endl;
    } else {
        std::cout << "Issue" << std::endl;
    }
    
    mPath = PathBuilder(path, name);
}

ArcaModule::ArcaModule(const std::filesystem::path& serilizedModuleFilePath) {
    mPath = serilizedModuleFilePath;
    if(Deserialize()) {
        std::cout << "Cool" << std::endl;
    }

    // Build all Containers
    for(const auto& path : mContainerVector) {
        ArcaContainer ar {path};
        auto container = std::make_shared<ArcaContainer>(ar);
        mContainerMap[container->GetName()] = container;
    }
}

bool ArcaModule::Serialize() {
    nlohmann::json moduleJson = Save();
    std::ofstream file(mPath);
    if (!file.is_open()) {
        return false;
    }
    file << moduleJson.dump(4);
    file.close();
    return true;
}

bool ArcaModule::Deserialize() {
    std::ifstream file(mPath);
    if(file.is_open()) {
        nlohmann::json moduleJson;
        file >> moduleJson;
        file.close();
        Load(moduleJson);
        return true;
    } else {
        std::cout << "Instance can't be deserialized" << std::endl;
        return false;
    }

}

std::filesystem::path ArcaModule::GetPath() {
    return mPath.parent_path();
}


std::filesystem::path ArcaModule::GetFilePath() {
    return mPath;
}

void ArcaModule::AddAsset(const std::string& key, const std::filesystem::path& path) {
    mAssetMap[key] = path;
}

std::filesystem::path ArcaModule::GetAsset(const std::string& key) {
    return mAssetMap[key];
}

bool ArcaModule::AddContainer(ArcaContainer& container) {
    mContainerVector.push_back(container.GetPath());
    std::string name = container.GetName();
    mContainerMap[name] = std::make_shared<ArcaContainer>(container);
    return true;
}


std::shared_ptr<ArcaContainer> ArcaModule::GetContainer(const std::string& key) {
    auto it = mContainerMap.find(key);
    if(it != mContainerMap.end()) {
        return mContainerMap.at(key);
    } else {
        std::cout << "This container is not exists!" << std::endl;
        return nullptr;
    }
}


std::filesystem::path ArcaModule::PathBuilder(const std::filesystem::path& path, const std::string& name) {
    return path / (name + ".json");
}


nlohmann::json ArcaModule::Save() {
    nlohmann::json json;

    nlohmann::json containerPaths = nlohmann::json::array();
    for (const auto& path : mContainerVector) {
        containerPaths.push_back(path.string());
    }
    json["ModulePaths"] = containerPaths;

    nlohmann::json assets = nlohmann::json::object();
    for (const auto& [key, path] : mAssetMap) {
        assets[key] = path.string();
    }
    json["Assets"] = std::move(assets);

    return json;
}

bool ArcaModule::Load(const nlohmann::json& fs) {
    if (!fs.is_object()) {
        return false;
    }

    if (!fs.contains("ModulePaths") || !fs["ModulePaths"].is_array()) {
        return false;
    }

    mContainerVector.clear();
    for (const auto& pathJson : fs["ModulePaths"]) {
        if (!pathJson.is_string()) {
            return false;
        }
        mContainerVector.emplace_back(pathJson.get<std::string>());
    }

    mAssetMap.clear();
    if (fs.contains("Assets")) {
        const auto& assetsJson = fs["Assets"];
        if (!assetsJson.is_object()) {
            return false;
        }

        for (auto it = assetsJson.begin(); it != assetsJson.end(); ++it) {
            if (!it.value().is_string()) {
                return false;
            }
            mAssetMap[it.key()] = it.value().get<std::string>();
        }
    }

    return true;    
}