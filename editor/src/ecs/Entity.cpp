#include "ecs/Entity.hpp"


//------------------------------------------------------------------------------
//                              CONSTRUCTORS
//------------------------------------------------------------------------------
Entity::Entity(const uint64_t& id, const Transform3D& transform) {
    mId = id;
    mTransform = transform;
}

Entity::Entity(const nlohmann::json& entityJson) {
    Deserializer(entityJson);
}

Entity::~Entity() {
    // Default destructor
}


//------------------------------------------------------------------------------
//                         ENTITY LIFE TIME FUNCTIONS
//------------------------------------------------------------------------------
void Entity::Start() {
    std::cout << "--------------------ETITY CREATED--------------------" << std::endl;
    std::cout << mId << std::endl;
    std::cout << "-----------------------------------------------------" << std::endl;

    for(auto& c : mComponenets) {
        c->Start();
    }
}

void Entity::Tick() {
    for(auto& c : mComponenets) {
        c->Tick();
    } 
}

void Entity::Destroy() {
    mComponenets.clear();
}


//------------------------------------------------------------------------------
//                         COMPONENT HANDLER
//------------------------------------------------------------------------------
void Entity::AddComponent(std::unique_ptr<Component> newComponent) {
    mComponenets.push_back(std::move(newComponent));
}

template<typename T>
T* Entity::GetComponent() {
    for(auto& c : mComponenets ) {
        if(auto p = dynamic_cast<T*>(c.get())) {
            return p;
        }
    }
    return nullptr;
}

template<typename T>
T* Entity::GetComponent(const uint64_t& id) {
    for(auto& c : mComponenets) {
        if(auto p = dynamic_cast<T*>(c.get())) {
            if (p->GetId() == id) {
                return p;
            }
        }
    }
    return nullptr;
}


//------------------------------------------------------------------------------
//                                SERIALIZERS
//------------------------------------------------------------------------------
nlohmann::json Entity::Serializer() {
    nlohmann::json entityJson;
    entityJson["id"] = mId;

    entityJson["TransformPosition"] = {
        {"x", mTransform.GetPos().x},
        {"y", mTransform.GetPos().y},
        {"z", mTransform.GetPos().z}
    };

        entityJson["TransformRotation"] = {
        {"pitch", mTransform.GetRot().x},
        {"roll", mTransform.GetRot().y},
        {"yaw", mTransform.GetRot().z}
    };

        entityJson["TransformScale"] = {
        {"x", mTransform.GetScale().x},
        {"y", mTransform.GetScale().y},
        {"z", mTransform.GetScale().z}
    };

    nlohmann::json componentsJson = nlohmann::json::object();
    for (auto& c : mComponenets) {
        nlohmann::json cj = c->ToSceneJson();
        if (cj.is_object()) {
            for (auto it = cj.begin(); it != cj.end(); ++it) {
                componentsJson[it.key()] = it.value();
            }
        }
    }

    entityJson["components"] = componentsJson;

    return entityJson;
}

void Entity::Deserializer(const nlohmann::json& entityJson) {
    if (!entityJson.is_object()) {
        throw std::runtime_error("Entity deserialization failed: JSON is not an object.");
    }


    mId = entityJson.value("id", static_cast<uint64_t>(0));

    const auto posIt = entityJson.find("TransformPosition");
    if (posIt != entityJson.end() && posIt->is_object()) {
        auto& pos = mTransform.GetPos();
        pos.x = posIt->value("x", pos.x);
        pos.y = posIt->value("y", pos.y);
        pos.z = posIt->value("z", pos.z);
    }

    const auto rotIt = entityJson.find("TransformRotation");
    if (rotIt != entityJson.end() && rotIt->is_object()) {
        auto& rot = mTransform.GetRot();
        rot.x = rotIt->value("pitch", rot.x);
        rot.y = rotIt->value("roll",  rot.y);
        rot.z = rotIt->value("yaw",   rot.z);
    }

    const auto scaleIt = entityJson.find("TransformScale");
    if (scaleIt != entityJson.end() && scaleIt->is_object()) {
        auto& s = mTransform.GetScale();
        s.x = scaleIt->value("x", s.x);
        s.y = scaleIt->value("y", s.y);
        s.z = scaleIt->value("z", s.z);
    }

    const auto compsIt = entityJson.find("components");
    if (compsIt != entityJson.end() && compsIt->is_object()) {
        mComponenets.clear();
        for (auto it = compsIt->begin(); it != compsIt->end(); ++it) {
            const std::string idStr = it.key();
            const nlohmann::json& data = it.value();
            mComponenets.push_back(ComponentBuilder(idStr, data));
        }
    }
}

std::unique_ptr<Component> Entity::ComponentBuilder(const std::string idStr, const nlohmann::json& data) {
    uint64_t id = static_cast<uint64_t>(std::hash<std::string>{}(idStr));

    std::string type = data["ComponentType"];

    // GOD I HATE THIS SHIT...... (I learned it from Pirate Software :D)
    // TO-DO: Make it better
    if (type == "SphereRender") {
        return std::make_unique<SphereRenderComponent>(id, data);
    } else {
        return nullptr;
    }
}



//------------------------------------------------------------------------------
//                                     GETERS
//------------------------------------------------------------------------------
uint64_t Entity::GetId() {
    return mId;
}

Transform3D& Entity::GetTransform() {
    return mTransform;
}
