#ifndef SESSION_HPP
#define SESSION_HPP

#include <filesystem>
#include <memory>
#include <string>
#include <fstream>
#include <iomanip>

#include <nlohmann/json.hpp>

#include "Arca.hpp"
#include "scene/Scene.hpp"
#include "session/SessionUtils.hpp"
#include "utils/Camera.hpp"

// Rendering Pipeline 
#include "kernels/RayGenKernel.hpp"

class Session {
    public:
        Session(const std::filesystem::path& sessionPath);
        void StartRenderingPipeline();
    private:
        bool mSessionStatus = false;
        std::filesystem::path mSessionPath;
        std::shared_ptr<Scene> mScene;
        std::shared_ptr<RenderLamp::Camera> mCamera;
        RenderLamp::SessionSettings mSessionSettings;

        bool DeserializeSession(const std::filesystem::path& sessionPath);
        RenderLamp::SessionSettings DeserilaizeSettings(const std::filesystem::path& sessionPath);
        
        bool DeserializeScene(const std::filesystem::path& scenePath);
        RenderLamp::Camera DeserializeCamera(const nlohmann::json& jsonObject);


        int mTotalRows = 0;
        int mCompletedRows = 0;
        int mLastBucket = -1;
        
        void PrintSessionSettings();
        void PrintCameraData();
        void PrintRenderProgressBar(const int& x);
        void InitProgressBar(const int& batchSum);
        void UpdateProgressBar();

};

#endif