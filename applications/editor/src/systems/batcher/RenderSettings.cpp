#include "systems/batcher/RenderSettings.hpp"

RenderSettings::RenderSettings(const std::string& containerName) {
    std::shared_ptr<ArcaContainer> tmpContainer = Arca::GetArcaModule("Editor")->GetContainer(containerName);

    mWidth = tmpContainer->GetValue<int>("TargetRenderWidth");
    mHeight = tmpContainer->GetValue<int>("TargetRenderHeight");
    mFov = tmpContainer->GetValue<double>("CameraFOV");
    mFocalLength = tmpContainer->GetValue<double>("FocalLength");
    mSamplePerPixel = tmpContainer->GetValue<int>("SamplePerPixel");
    mMaxDepth = tmpContainer->GetValue<int>("MaxDepth");
}