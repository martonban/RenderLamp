#ifndef ARCA_CONTAINER_HPP
#define ARCA_CONTAINER_HPP

#include <map>
#include <any>
#include <string>
#include <filesystem>
#include <iostream>

class ArcaContainer {
    public:
        ArcaContainer(const std::filesystem::path& path, const std::string& fileName);
        bool Load();
        bool Save();


        void AddPair(const std::string& key, const std::any& value);
        
 
        template<typename T>
        T GetValue(const std::string& key) {
            auto i = mContainer[key];
            return std::any_cast<T>(i);
        }

    private:
        std::filesystem::path mPath;
        std::map<std::string, std::any> mContainer;
};

#endif