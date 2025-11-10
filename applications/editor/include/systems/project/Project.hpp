#ifndef PROJECT_HPP
#define PROJECT_HPP

#include <string>
#include <filesystem>

#include "Arca.hpp"
#include "systems/scene/models/Scene.hpp"

class Project {
    public:
        Project(const std::string& name, const std::filesystem::path& path, std::shared_ptr<Scene>);
        Project(const std::filesystem::path& path, std::shared_ptr<Scene>& scene);
    private:
        std::unique_ptr<ArcaModule> mProjectModule;
        //void BuildProject(const std::string& name, const std::filesystem::path& path, Scene& scene);
        //Scene& LoadProject();
};

#endif