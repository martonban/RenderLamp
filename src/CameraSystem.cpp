#include "CameraSystem.h"

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
    }

    //final_position = CalculateFinalPosition(based_on_input_position, final_rotation);

    UpdateCameraPro(&camera, based_on_input_position, final_rotation,
                    CameraControllerZoomListener());
}


/*
void CameraSystem::UpdateCamera () {
    UpdateCameraPro(&camera, CameraControllerMovementListener(), CameraControllerRotationListener(),
                    CameraControllerZoomListener());
}
*/

Vector3 CameraSystem::CameraControllerMovementListener() {
    //Vector3 delta = Vector3Normalize(camera.target);
    Vector3 delta = {0};
        // TODO CURSOR HIDE
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

/*
Vector3 CalculateFinalPostion(Vector3 pos, Vector3 rot) {

}
*/

float CameraSystem::CameraControllerZoomListener() {
    return -(GetMouseWheelMove());
}