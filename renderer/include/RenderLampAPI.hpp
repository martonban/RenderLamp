#ifndef RENDER_LAMP_API_HPP
#define RENDER_LAMP_API_HPP

#include <string>

#include "nlohmann/json.hpp"
#include "Arca.hpp"

namespace RenderLamp {
    /**
     * @brief Initialize the renderer with specific settings
     * @param renderConfigPath A .json filepath 
     * @return True if initialization succeeded
    */
    bool InitRenderer(const std::string& renderConfigPath);

}

#endif