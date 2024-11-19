#ifndef RENDERER_RAYLIB_H
#define RENDERER_RAYLIB_H

#include "raylib.h"


class RendererRayLib {
    // Functions 
    public: 
        RendererRayLib() {
            camera.position = {10.0, 10.0, 10.0};
            camera.target = { 0.0, 0.0, 0.0 };
            camera.up = { 0.0, 1.0, 0.0 };          
            camera.fovy = 45.0f;                                
            camera.projection = CAMERA_PERSPECTIVE;  
        }

        void Start();
        void RenderLoop();


    // Data Fields
    private:
        Camera3D camera = { 0 };
};

#endif