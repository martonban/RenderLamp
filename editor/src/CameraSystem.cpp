#include "CameraSystem.hpp"

void CameraSystem::StartCamera() {
    camera.position = {10.0, 10.0, 10.0};
    camera.target = { 0.0, 0.0, 0.0 };
    camera.up = { 0.0, 1.0, 0.0 };          
    camera.fovy = 45.0f;                                
    camera.projection = CAMERA_PERSPECTIVE;
}

void CameraSystem::UpdateCamera () {
    Vector3 final_position = {0};
    Vector3 based_on_input_position = {0};
    Vector3 final_rotation = {0};
    if(IsMouseButtonDown(MOUSE_BUTTON_RIGHT)) {
        based_on_input_position = CameraControllerMovementListener();
        final_rotation = CameraControllerRotationListener();
        final_position = Vector3Add(CalculateFinalPostion(based_on_input_position, final_rotation), based_on_input_position);
        HideCursor();
    } else {
        ShowCursor();
    }

    UpdateCameraPro(&camera, final_position, final_rotation,
                    CameraControllerZoomListener());
}


Vector3 CameraSystem::CameraControllerMovementListener() {
    //Vector3 delta = Vector3Normalize(camera.target);
    Vector3 delta = {0};
    if (IsKeyDown(KEY_W)){
        delta.x += 0.01f;
    } else if (IsKeyDown(KEY_S)) {
        delta.x -= 0.01f;
    } else if (IsKeyDown(KEY_D)) {
        delta.y += 0.01f;
    }  else if (IsKeyDown(KEY_A)) {
         delta.y -= 0.01f;
    }
    return delta;
}


Vector3 CameraSystem::CameraControllerRotationListener() {
    return Vector3(GetMouseDelta().x/10, GetMouseDelta().y/10, 0.0f);
}

Vector3 CameraSystem::CalculateFinalPostion(Vector3 pos, Vector3 rot) {
    Vector3 result = {0};
    if(IsKeyDown(KEY_LEFT_SHIFT)) {
        result.z += 0.005f;
    } else if(IsKeyDown(KEY_LEFT_CONTROL)) {
        result.z -= 0.005f;
    }
    return result;
}

float CameraSystem::CameraControllerZoomListener() {
    return -(GetMouseWheelMove());
}

Vector3 CameraSystem::GetLookDirectionNormalVector() {
    return Vector3Normalize(Vector3Subtract(camera.position, camera.target));
}