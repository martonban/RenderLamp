#ifndef ARCA_CONTAINER_HPP
#define ARCA_CONTAINER_HPP

#include <iostream>
#include <filesystem>
#include <any>
#include <map>
#include <memory>
#include <variant>
#include <nlohmann/json.hpp>

using Record = std::variant<int, float, double, std::string, std::filesystem::path>;

class ArcaContainer {
    public:
        ArcaContainer(const std::filesystem::path& path);
        bool AddPair(const std::string& key, std::any& value);
        std::any GetValue(const std::string& key);
        void Serialize();
        void Deserialize();
    private:
        Record Converter(const std::any& value);
        std::filesystem::path mPath;
        std::map<std::string, Record> mContainer;

};


#endif