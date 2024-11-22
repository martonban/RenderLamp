#include "CameraSystem.h"

void CameraSystem::StartCamera() {
    camera.position = {10.0, 10.0, 10.0};
    camera.target = { 0.0, 0.0, 0.0 };
    camera.up = { 0.0, 1.0, 0.0 };          
    camera.fovy = 45.0f;                                
    camera.projection = CAMERA_PERSPECTIVE;  
}


void CameraSystem::UpdateCamera () {
    UpdateCameraPro(&camera, CameraControllerMovementListener(), CameraControllerRotationListener(),
                    CameraControllerZoomListener());
}


Vector3 CameraSystem::CameraControllerMovementListener() {
    Vector3 delta = {0};
    if (IsMouseButtonDown(MOUSE_BUTTON_RIGHT)) {
        // TODO CURSOR HIDE
        if (IsKeyDown(KEY_W)){
            delta = Vector3Add(delta, Vector3(0.01f, 0.0f, 0.0f));
        } else if (IsKeyDown(KEY_S)) {
            delta = Vector3Add(delta, Vector3(-0.01f, 0.0f, 0.0f));
        } else if (IsKeyDown(KEY_D)) {
            delta = Vector3Add(delta, Vector3(0.0f, 0.01f, 0.0f));
        }  else if (IsKeyDown(KEY_A)) {
            delta = Vector3Add(delta, Vector3(0.0f, -0.01f, 0.0f));
        } 
    }
    return delta;
}

Vector3 CameraSystem::CameraControllerRotationListener() {
     if (IsMouseButtonDown(MOUSE_BUTTON_RIGHT)) {
        return Vector3(GetMouseDelta().x/10, GetMouseDelta().y/10, 0.0f);
     }
    return {0};
}

float CameraSystem::CameraControllerZoomListener() {
    return -(GetMouseWheelMove());
}