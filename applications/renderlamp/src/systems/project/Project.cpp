#include "systems/project/Project.hpp"

Project::Project(const std::string& name, const std::filesystem::path& path, std::shared_ptr<Scene> scene) {
    mProjectModule = std::make_unique<ArcaModule>(path, name);
    mProjectModule->Serialize();
    scene->Serialize(mProjectModule->GetPath() / "Scene.json");
}


Project::Project(const std::filesystem::path& path, std::shared_ptr<Scene>& scene) {
    mProjectModule = std::make_unique<ArcaModule>(path);

    // Get Editor Config 
    std::shared_ptr<ArcaContainer> editorDefaultValues = Arca::GetArcaModule("Editor")->GetContainer("EditorConfig");
    int height = editorDefaultValues->GetValue<int>("WindowWidth");
    int width = editorDefaultValues->GetValue<int>("WindowHeight");

    scene = std::make_shared<Scene>(height, width);

    std::cout << path << std::endl;
    scene->Deserialize(path.parent_path() / "Scene.json");
}