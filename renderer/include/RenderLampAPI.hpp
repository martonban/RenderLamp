#ifndef RENDER_LAMP_API_HPP
#define RENDER_LAMP_API_HPP

#include <string>

#include "nlohmann/json.hpp"
#include "Arca.hpp"

namespace RenderLamp {
    //-----------------------------------------------------------------------------------
    //                              BUZZ RENDERER
    //-----------------------------------------------------------------------------------    
    /**
     * @brief Initialize Buzz Renderer
     * @param renderConfigPath A .json filepath 
     * @return True if initialization succeeded
    */
    inline bool InitBuzzRendererInstance(const std::string& renderConfigPath) {
        return true;
    }

}

#endif