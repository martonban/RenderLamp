#ifndef CAMERA_SYSTEM_HPP
#define CAMERA_SYSTEM_HPP

#include <iostream>

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
        Vector3 CameraControllerMovementListener();
        Vector3 CameraControllerRotationListener();
        float CameraControllerZoomListener();
        Vector3 CalculateFinalPostion(Vector3 pos, Vector3 rot);
        Vector3 GetLookDirectionNormalVector();
    private:
        Camera3D camera {0};
};

#endif