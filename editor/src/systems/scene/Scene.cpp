#include "systems/scene/Scene.hpp"

//------------------------------------------------------------------------------
//                              CONSTRUCTORS
//------------------------------------------------------------------------------
Scene::Scene(const int& width, const int& height) {
    mRenderer = std::make_unique<RealTimeRenderingSystem>(width, height);
}


//------------------------------------------------------------------------------
//                          SCENE LIFE TIME FUNCTIONS
//------------------------------------------------------------------------------
void Scene::Start() {
    mRenderer->RenderingAllocation();
    
    for(auto& e : mEntityVector) {
        e->Start();
    }
}

void Scene::Update() {
    mRenderer->Render();
    mRenderer->DrawFramebuffer();
    for(auto& e : mEntityVector) {
        e->Tick();
    }
}

void Scene::Destroy() {
    for(auto& e : mEntityVector) {
        e->Destroy();
    }
    
    mEntityVector.clear();
    mRenderer->DestroyRenderer();

}


//------------------------------------------------------------------------------
//                              Entity Handlers
//------------------------------------------------------------------------------
void Scene::AddEntity(std::unique_ptr<Entity> newComponent) {
    mEntityVector.push_back(std::move(newComponent));
}


//------------------------------------------------------------------------------
//                                 Serializer
//------------------------------------------------------------------------------
bool Scene::Serialize(const std::filesystem::path& outPath) const {
    std::ofstream file(outPath);
    if (!file.is_open()) return false;

    const nlohmann::json j = SceneToJson();
    file << j.dump(4);
    return true;
}

nlohmann::json Scene::SceneToJson() const {
    nlohmann::json root;
    nlohmann::json entities = nlohmann::json::array();

    for (const auto& ent : mEntityVector) {
        if (ent) {
            entities.push_back(ent->Serializer());
        }
    }

    root["entities"] = entities;
    return root;
}


//------------------------------------------------------------------------------
//                                Deserializer
//------------------------------------------------------------------------------
bool Scene::Deserialize(const std::filesystem::path& outPath) {
    std::ifstream file(outPath);
    if(file.is_open()) {
        nlohmann::json sceneJson;
        file >> sceneJson;
        file.close();
        JsonToScene(sceneJson);
        return true;
    } else {
        std::cout << outPath << std::endl;
        std::cout << "Scene can't be deserialized" << std::endl;
        return false;
    }
}

void Scene::JsonToScene(const nlohmann::json& sceneJson) {
    if (!sceneJson.is_object()) {
        std::cerr << "Scene Deserializer json object is not a JSON" << std::endl;
        return;
    }

    const auto entitiesIt = sceneJson.find("entities");
    if (entitiesIt == sceneJson.end() || !entitiesIt->is_array()) {
        std::cerr << "Scene Desirilizer issue. Scene does not contain entites" << std::endl;
        return;
    }

    if (!mEntityVector.empty()) {
        mEntityVector.clear();
    }


    for (const auto& entityJson : *entitiesIt) {
        if (!entityJson.is_object()) {
            std::cerr << "[Scene::JsonToScene] Egy 'entity' nem object, kihagyva." << std::endl;
            continue;
        }

        try {
            mEntityVector.push_back(std::move(std::make_unique<Entity>(entityJson)));
        } catch (const std::exception& e) {
            std::cerr << "Scene Deserilaizer. Issue has been accured " << e.what() << std::endl;
        }
    }
}