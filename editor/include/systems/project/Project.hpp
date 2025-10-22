#ifndef PROJECT_HPP
#define PROJECT_HPP

#include <string>
#include <filesystem>


class Project {
    public:
        Project(const std::string& name, const std::filesystem::path& path);
    private:
        std::filesystem::path mPath;
};

#endif