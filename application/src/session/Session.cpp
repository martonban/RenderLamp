#include "session/Session.hpp"

Session::Session(const std::filesystem::path& sessionPath) {
    if(DeserializeSession(sessionPath)) {
        // Deserialze Session
        
        PrintSessionSettings();
        // Assembly Rendering Kernels
    }
}

bool Session::DeserializeSession(const std::filesystem::path& sessionPath) {
    // File Existance Validation Stage
    if(Arca::ArcaIO::IsFileExists(sessionPath / "Scene.json") && Arca::ArcaIO::IsFileExists(sessionPath / "SessionSettings.json")) {
        mSessionSettings = DeserilaizeSettings(sessionPath / "SessionSettings.json");
        return true;
    } else {
        return false;
    }
}

RenderLamp::SessionSettings Session::DeserilaizeSettings(const std::filesystem::path& sessionPath) {
    RenderLamp::SessionSettings settings = {};
    nlohmann::json j;
    
    std::ifstream file(sessionPath);
    if(!file.is_open()) {
        std::cerr << "Session.json is not exist!" << std::endl;
        return settings;
    }

    file >> j;
    settings.sessionName = j["SessionName"];
    settings.sessionPath = sessionPath.parent_path();
    settings.engine = static_cast<RenderLamp::RenderEngine>(j["RenderEngine"]);
    settings.mode = static_cast<RenderLamp::LightSimMode>(j["Mode"]);
    settings.device = static_cast<RenderLamp::Device>(j["Device"]);
    settings.imageWidth = j["TargetWidth"];
    settings.imageHeight = j["TargetHeight"];
    settings.samples = j["Samples"];
    settings.maxDepth = j["Depth"];

    return settings;
} 


void Session::PrintSessionSettings() {
    std::cout << "=== Session Settings ===" << std::endl;
    std::cout << "Session Name: " << mSessionSettings.sessionName << std::endl;
    std::cout << "Session Path: " << mSessionSettings.sessionPath << std::endl;
    std::cout << "Render Engine: " << mSessionSettings.engine << std::endl;
    std::cout << "Light Sim Mode: " << mSessionSettings.mode << std::endl;
    std::cout << "Device: " << mSessionSettings.device << std::endl;
    std::cout << "Image Width: " << mSessionSettings.imageWidth << std::endl;
    std::cout << "Image Height: " << mSessionSettings.imageHeight << std::endl;
    std::cout << "Samples: " << mSessionSettings.samples << std::endl;
    std::cout << "Max Depth: " << mSessionSettings.maxDepth << std::endl;
}