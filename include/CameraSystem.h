#ifndef CAMERA_SYSTEM_H
#define CAMERA_SYSTEM_H

#include "raylib.h"
#include "raymath.h"

class CameraSystem {
    // Funcions
    public:
        void StartCamera();
        void UpdateCamera();
        Camera3D GetCameraInstance( void ) {
            return camera;
        };
    private: 
        Vector3 CameraControllerMovementListener();
        Vector3 CameraControllerRotationListener();
        float CameraControllerZoomListener();
    
    // Data fileds
    private:
        Camera3D camera {0};
};

#endif