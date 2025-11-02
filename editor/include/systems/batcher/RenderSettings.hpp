#ifndef RENDER_SETTINGS_HPP
#define RENDER_SETTINGS_HPP

#include <string>
#include <memory>

#include "Arca.hpp"

class RenderSettings {
    public:
        RenderSettings(const std::string& containerName);
        // TO-DO Implement later 
        //nlohmann::json Serialize();
    private:
        int mWidth;
        int mHeight;
        double mFov;
        double mFocalLength;
        int mSamplePerPixel;
        int mMaxDepth;
};

#endif