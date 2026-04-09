#include "session/Session.hpp"


Session::Session(const std::filesystem::path& sessionPath) {
    if(DeserializeSession(sessionPath)) {
        mSessionPath = sessionPath;
        if(DeserializeScene(sessionPath / "Scene.json")) {
            PrintCameraData();
            mSessionStatus = true;
        } else {
            std::cerr << "Invalid Scene!" << std::endl;
        }
    } else {
        std::cerr << "Invalid Session!" << std::endl;
    }
}


void Session::StartRenderingPipeline() {
    int batchSum = 10;
    if(!Arca::ArcaIO::CreateFolder(mSessionPath, mSessionSettings.sessionName)) {
        std::cerr << "Output folder creation issue" << std::endl;
    }

    if(mSessionStatus == true) {
        InitProgressBar(batchSum);
        // Batch Loop
        for(int b = 0; b < batchSum; b++) {
            // SceneDeserilize();
            std::string frameName = "frame_" + std::to_string(b) + ".ppm";
            std::ofstream file(mSessionPath / mSessionSettings.sessionName / frameName);
            // RenderLamp::PowderRenderer::VertexTransformStage(mScene, mBatch);
            
            file << "P3\n" << mSessionSettings.imageWidth << ' ' << mSessionSettings.imageHeight << "\n255\n"; 
            // Frame Loop
            for (int j = 0; j < mSessionSettings.imageHeight; j++) {
                for (int i = 0; i < mSessionSettings.imageWidth; i++) {
                    Ray ray = {};
                    HitRecord hr = {};
                    int ir, ig, ib;
                    RenderLamp::PowderRenderer::RayGenaration(ray, i, j, mCamera);
                    RenderLamp::PowderRenderer::RayIntersection(ray, hr, mScene);
                    RenderLamp::PowderRenderer::ShadingKernel(hr, ray, ir, ig, ib);

                    file << ir << ' ' << ig << ' ' << ib << '\n';
                }
                UpdateProgressBar();
            }
        }
        PrintRenderProgressBar(20);
        std::cout << std::endl;
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
    settings.frameRate = j["FrameRate"];

    return settings;
} 


bool Session::DeserializeScene(const std::filesystem::path& scenePath) {
    nlohmann::json json;
    std::ifstream file(scenePath);
    if(!file.is_open()) {
        std::cerr << "Scene.json is not exist!" << std::endl;
        return false;
    }

    file >> json;
    mCamera = std::make_shared<RenderLamp::Camera>(DeserializeCamera(json));
    mCamera->Process(mSessionSettings);
    
    std::shared_ptr<Mesh> m1 = std::make_shared<Mesh>(glm::dvec3{0.0, 0.0, 0.0}, glm::dvec3{0.174532935023308, 0.0, 0.0}, glm::dvec3{0.25, 0.25, 0.25}, "C:/Project/Big Projects/RenderLamp/tool/Meshes/utah_teapot.obj");
    Material mat1 { DIFFUSE_SHADER, glm::ivec3{75, 10, 100}, 0.0, 0.0 };
    m1->AddMaterial(mat1);
    mScene->AddGeometryToTheScene(m1);
    //std::shared_ptr<Sphere> s1 = std::make_shared<Sphere>(glm::dvec3{-0.734, 0.619, -0.304}, 0.5);
    //mScene->AddGeometryToTheScene(s1);
    return true;
}

RenderLamp::Camera Session::DeserializeCamera(const nlohmann::json& jsonObject) {
    if(jsonObject.contains("camera")) {
        nlohmann::json camera_json = jsonObject["camera"];
        nlohmann::json coords = camera_json["position"];

        glm::dvec3 pos {0.0, 0.0, 0.0}; 
        double fov = 0.0;

        pos.x = coords["x"];
        pos.y = coords["y"];
        pos.z = coords["z"];
    
        fov = camera_json["fov"];

        return RenderLamp::Camera {pos, fov};
    } else {
        std::cerr << "Camera is not exits in the scene" << std::endl;
        return RenderLamp::Camera {{0.0, 0.0, 0.0}, 0.0}; 
    }
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
    std::cout << "Frame Rate:" << mSessionSettings.frameRate << std::endl;
}

void Session::PrintCameraData() {
    std::cout << "=== Camera Data ===" << std::endl;
    std::cout << "Position X: " << mCamera->wordPos.x << std::endl;
    std::cout << "Position Y: " << mCamera->wordPos.y << std::endl;
    std::cout << "Position Z: " << mCamera->wordPos.z << std::endl;
    std::cout << "FOV: " << mCamera->fov << std::endl;
}

void Session::PrintRenderProgressBar(const int& x) {
    constexpr int barWidth = 20;
    int clampedX = x;
    if(clampedX < 0) clampedX = 0;
    if(clampedX > barWidth) clampedX = barWidth;

    const std::string done(clampedX, '#');
    const std::string remaining(barWidth - clampedX, '-');

    std::cout << "\r[" << done << remaining << "] "
              << std::setw(3) << (clampedX * 5) << "%" << std::flush;
}

void Session::InitProgressBar(const int& batchSum) {
    mTotalRows = batchSum * mSessionSettings.imageHeight;
    mCompletedRows = 0;
    mLastBucket = -1;
}

void Session::UpdateProgressBar() {
    mCompletedRows++;
    int percent = (mCompletedRows * 100) / mTotalRows;
    int bucket = percent / 5;
    if(bucket > 20) bucket = 20;
    if(bucket != mLastBucket) {
        PrintRenderProgressBar(bucket);
        mLastBucket = bucket;
    }
}

