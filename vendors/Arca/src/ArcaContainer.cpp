#include "ArcaContainer.hpp"
#include <fstream>
#include <iostream>

ArcaContainer::ArcaContainer(const std::filesystem::path& path) {
    mPath = path;
}

bool ArcaContainer::AddPair(const std::string& key, std::any& value) {
    try {
        Record tmp = Converter(value);
        mContainer[key] = tmp;
        return true;
    } catch(const std::bad_any_cast& e) {
        std::cout << "Wrong type" << std::endl;
        return false;
    }
}

std::any ArcaContainer::GetValue(const std::string& key) {
    return mContainer[key];
}

Record ArcaContainer::Converter(const std::any& value) {
    if(value.type() == typeid(int)) {
        return std::any_cast<int>(value);
    } else if (value.type() == typeid(float)) {
        return std::any_cast<float>(value);
    } else if (value.type() == typeid(double)) {
        return std::any_cast<double>(value);
    } else if (value.type() == typeid(std::string)) {
        return std::any_cast<std::string>(value);
    } else if (value.type() == typeid(std::filesystem::path)) {
        return std::any_cast<std::filesystem::path>(value);
    } else {
        throw std::bad_any_cast();
    }
}


void ArcaContainer::Serialize() {
    nlohmann::json j;
    for (const auto& [key, value] : mContainer) {
        if (std::holds_alternative<int>(value)) {
            j[key] = std::get<int>(value);
        } else if (std::holds_alternative<float>(value)) {
            j[key] = std::get<float>(value);
        } else if (std::holds_alternative<double>(value)) {
            j[key] = std::get<double>(value);
        } else if (std::holds_alternative<std::string>(value)) {
            j[key] = std::get<std::string>(value);
        } else if (std::holds_alternative<std::filesystem::path>(value)) {
            j[key] = std::get<std::filesystem::path>(value).string();
        }
    }
    std::ofstream ofs(mPath);
    if (!ofs) {
        throw std::runtime_error("Failed to open file for serialization: " + mPath.string());
    }
    ofs << j.dump(4);
    if (ofs.fail()) {
        throw std::runtime_error("Failed to write JSON to file: " + mPath.string());
    }
}

void ArcaContainer::Deserialize() {
    std::ifstream ifs(mPath);
    if (!ifs) {
        throw std::runtime_error("Failed to open file for deserialization: " + mPath.string());
    }
    nlohmann::json j;
    ifs >> j;
    mContainer.clear();
    for (auto it = j.begin(); it != j.end(); ++it) {
        // Try to detect type
        if (it->is_number_integer()) {
            mContainer[it.key()] = it->get<int>();
        } else if (it->is_number_float()) {
            mContainer[it.key()] = it->get<double>();
        } else if (it->is_string()) {
            std::string str = it->get<std::string>();
            if (str.find('/') != std::string::npos || str.find('\\') != std::string::npos) {
                mContainer[it.key()] = std::filesystem::path(str);
            } else {
                mContainer[it.key()] = str;
            }
        }
    }
}