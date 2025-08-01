//------------------------------------------------------------------------------------------------
//                                   RenderLamp - RenderingSystem
//                                      Márton Bán (C) 2025
//	
//  The RenderingSystem class is a wrapper responsible for initializing both the editor renderer 
//  and the ray tracer renderer instances. It also serves as a service layer for handling
//  editor-side rendering requests.
//
//  The DCC editor expects a framebuffer, which will be provided by the SceneManager. Later on, 
//  the SceneManager will also supply the RenderingSystem with the necessary scene data. This 
//  renderer will be placed in here. 
//
//  For the ray tracer, the RenderingSystem acts as an intermediary layer between the editor and
//  the ray tracing backend.
//------------------------------------------------------------------------------------------------

#ifndef RENDERING_SYSTEM_HPP
#define RENDERING_SYSTEM_HPP

#include "raylib.h"

class RenderingSystem {
public: 
    RenderingSystem(const int& framebufferWidth, const int& framebufferHeight);
    void RenderingAllocation();
    void Render();
    void DrawFramebuffer();
    void DestroyRenderer();
public:
    const int mFramebufferWidth;
    const int mFramebufferHeight;

    RenderTexture2D mRenderTarget = {0};
    Camera3D mCamera = {0};
    // TODO: INIT RenderLamp ray tracing renderer
    // TODO: Renderer will need ARCA  
};


#endif 