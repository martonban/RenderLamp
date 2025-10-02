#include "ArcaContainer.hpp"

ArcaContainer::ArcaContainer(const std::filesystem::path& path, const std::string& fileName) {
    mPath = path / (fileName + ".json");
}

bool ArcaContainer::Dispatch() {
    nlohmann::json instanceJson = Save();
    std::ofstream file(mPath);
    if (!file.is_open()) {
        return false;
    }
    file << instanceJson.dump(4);
    file.close();
    return true;
}

nlohmann::json ArcaContainer::Save() {
    nlohmann::json json;
    for (const auto& [key, value] : mContainer) {
        nlohmann::json entry;
        try {
            if (value.type() == typeid(int)) {
                entry["type"]  = "int";
                entry["value"] = std::any_cast<int>(value);
            } else if (value.type() == typeid(float)) {
                entry["type"]  = "float";
                entry["value"] = std::any_cast<float>(value);
            } else if (value.type() == typeid(double)) {
                entry["type"]  = "double";
                entry["value"] = std::any_cast<double>(value);
            } else if (value.type() == typeid(bool)) {
                entry["type"]  = "bool";
                entry["value"] = std::any_cast<bool>(value);
            } else if (value.type() == typeid(std::string)) {
                entry["type"]  = "string";
                entry["value"] = std::any_cast<std::string>(value);
            } else if (value.type() == typeid(std::filesystem::path)) {
                entry["type"]  = "path";
                entry["value"] = std::any_cast<std::filesystem::path>(value).string();
            } else {
                entry["type"]  = "unsupported";
                entry["value"] = std::string(value.type().name());
            }
        } catch (const std::exception&) {
            entry["type"]  = "error";
            entry["value"] = nullptr;
        }
        json[key] = std::move(entry);
    }
    return json;
}

bool ArcaContainer::Unpack() {
    std::ifstream file(mPath);
    if (!file.is_open()) return false;
    nlohmann::json json;
    file >> json;
    return Load(json);
}

bool ArcaContainer::Load(const nlohmann::json& fs) {
    mContainer.clear();
    for(const auto& [key, value] : fs.items()) {
        const auto& type = value["type"].get<std::string>();
        if (type == "int")          mContainer[key] = value["value"].get<int>();
        else if (type == "float")   mContainer[key] = value["value"].get<float>();
        else if (type == "double")  mContainer[key] = value["value"].get<double>();
        else if (type == "bool")    mContainer[key] = value["value"].get<bool>();
        else if (type == "string")  mContainer[key] = value["value"].get<std::string>();
        else if (type == "path")    mContainer[key] = std::filesystem::path(value["value"].get<std::string>());
    }
    return true;
}


void ArcaContainer::AddPair(const std::string& key, const std::any& value) {
    mContainer[key] = value;
}

