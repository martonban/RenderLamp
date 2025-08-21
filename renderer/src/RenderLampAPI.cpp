#include "RenderLampAPI.hpp"


bool RenderLamp::InitRenderer(const std::string& renderConfigPath) {
    bool flag = false;
    if(Arca::IsFileExists(renderConfigPath)) {
        return true;
    } else {
        return false;
    }
}