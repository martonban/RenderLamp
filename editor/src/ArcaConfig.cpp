#include "ArcaConfig.hpp"

ArcaConfig::ArcaConfig(const std::string& cofigFilePath) {
    // TODO: Fetch from a real config data
    mConfigData.insert({"window_width", "1000"});
    mConfigData.insert({"window_height", "800"});
    mConfigData.insert({"window_name", "RenderLamp Editor"});
}

void ArcaConfig::AddValue(const std::string& key, const std::string& value) {
    mConfigData.insert({key, value});
}

std::string ArcaConfig::GetStringValue(const std::string& key) {
    return mConfigData[key];
}

float ArcaConfig::GetFloatValue(const std::string& key) {
    return std::atof(mConfigData[key].c_str());
}

int ArcaConfig::GetIntValue(const std::string& key) {
    return std::atoi(mConfigData[key].c_str());
}
