#include "raylib.h"
#include "renderer.h"
#include "Application.h"

int main(void)
{

    Application& render_lamp_app = Application::GetInstance();

    render_lamp_app.Init();
    render_lamp_app.Start();

    const int screenWidth = 1800;
    const int screenHeight = 900;

    InitWindow(screenWidth, screenHeight, "RenderLamp Editor");

    SetTargetFPS(60);
    Renderer renderer; 
    int a = renderer.Test();


    while (!WindowShouldClose()) {
        BeginDrawing();

        ClearBackground(RAYWHITE);
        DrawText("Push F5 to render", 0, 0, 10, RED);
        DrawText("Congrats! You created your first window!", 190, 200, a, LIGHTGRAY);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}