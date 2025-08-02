#ifndef RENDER_LAMP_API_HPP
#define RENDER_LAMP_API_HPP

#ifdef __cplusplus
extern "C" {
#endif


#include <string>

namespace RenderLamp {
    /**
     * @brief Initialize the renderer with specific settings
     * @param renderConfigPath A .json filepath 
     * @return True if initialization succeeded
    */
    bool static InitRenderer(const std::string& renderConfigPath);

}

#ifdef __cplusplus
}
#endif

#endif