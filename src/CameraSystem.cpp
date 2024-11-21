#include "CameraSystem.h"

void CameraSystem::StartCamera() {
    camera.position = {10.0, 10.0, 10.0};
    camera.target = { 0.0, 0.0, 0.0 };
    camera.up = { 0.0, 1.0, 0.0 };          
    camera.fovy = 45.0f;                                
    camera.projection = CAMERA_PERSPECTIVE;  
}


void CameraSystem::UpdateCamera () {
    UpdateCameraPro(&camera, { 0.001f, 0.0f, 0.0f }, {0.0f}, 0.0f);
}