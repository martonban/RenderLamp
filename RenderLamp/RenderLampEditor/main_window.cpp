/*******************************************************************************************
*
* 
*
* 
* 
* 
********************************************************************************************/

#include "raylib.h"


int main(void) {
    //-----------------------------------
    //            Init
    //-----------------------------------
    const int screenWidth = 1700;
    const int screenHeight = 900;

    InitWindow(screenWidth, screenHeight, "RenderLamp Editor - Buzz Renderer");

    Camera3D camera = { 0 };
    camera.position = { 10.0f, 10.0f, 10.0f }; 
    camera.target = { 0.0f, 0.0f, 0.0f };
    camera.up = { 0.0f, 1.0f, 0.0f };
    camera.fovy = 45.0f;
    camera.projection = CAMERA_PERSPECTIVE;

    Vector3 cubePosition = { 0.0f, 0.0f, 0.0f };


    SetTargetFPS(60);
    while (!WindowShouldClose()) {
        //-----------------------------------
        //            Debug GUI
        //-----------------------------------


        //-----------------------------------
        //            Update
        //-----------------------------------
        UpdateCameraPro(&camera, { 0.0, 0.0, 0.0 }, {0.0, 0.0, 0.0}, 0.0);


        //-----------------------------------
        //            Drawing
        //-----------------------------------
        BeginDrawing();

        ClearBackground(RAYWHITE);

        BeginMode3D(camera);

        DrawCube(cubePosition, 2.0f, 2.0f, 2.0f, RED);
        DrawCubeWires(cubePosition, 2.0f, 2.0f, 2.0f, MAROON);

        DrawGrid(10, 1.0f);

        EndMode3D();

        //-----------------------------------
        //             GUI Draw
        //-----------------------------------

        // Title
        DrawText("RenderLamp - Buzz Renderer", 20, 20, 10, BLACK);

        // Menu background
        DrawRectangle( 1400 , 0, 320, 900, Fade(SKYBLUE, 0.5f));
        DrawRectangleLines( 1400, 0, 320, 900, BLUE);
        

        EndDrawing();
    }

    CloseWindow();
    return 0;
}