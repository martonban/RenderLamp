#ifndef CAMERA_SYSTEM_H
#define CAMERA_SYSTEM_H

#include "raylib.h"

class CameraSystem {
    // Funcions
    public:
        void StartCamera();
        void UpdateCamera();
        Camera3D GetCameraInstance( void ) {
            return camera;
        };
    
    // Data fileds
    private:
        Camera3D camera {0};
};

#endif