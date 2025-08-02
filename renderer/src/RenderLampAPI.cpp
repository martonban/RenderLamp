#include "RenderLampAPI.hpp"

bool RenderLamp::InitRenderer(const std::string& renderConfigPath) {
    if(Arca::IsFileExists(renderConfigPath)) {
        return true;
    } else {
        return false;
    }
}