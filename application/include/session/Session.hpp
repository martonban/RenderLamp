#ifndef SESSION_HPP
#define SESSION_HPP

#include <filesystem>
#include <memory>
#include <string>
#include <fstream>

#include "Arca.hpp"
#include "scene/Scene.hpp"
#include "session/SessionUtils.hpp"

#include <nlohmann/json.hpp>

class Session {
    public:
        Session(const std::filesystem::path& sessionPath);
        void StartRenderingPipeline();
    private:
        bool DeserializeSession(const std::filesystem::path& sessionPath);
        RenderLamp::SessionSettings DeserilaizeSettings(const std::filesystem::path& sessionPath);
        void PrintSessionSettings();
        std::shared_ptr<Scene> mScene;
        RenderLamp::SessionSettings mSessionSettings;
};

#endif