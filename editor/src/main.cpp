/****************************************************************************
 *                             RenderLamp - main.cpp
 *                         Copyright (c) Márton Bán 2024
 *
 *  This is going to be the entry point of the application.  
 * 
****************************************************************************/

#include "raylib.h"
#include "raymath.h"


/*
#include "../../thirdparty/imgui/include/imgui.h"
#include "../../thirdparty/rlImGui/include/rlImGui.h"
*/
#include "imgui.h"
#include "rlImGui.h"


// DPI scaling functions
float ScaleToDPIF(float value)
{
    return GetWindowScaleDPI().x * value;
}

int ScaleToDPII(int value)
{
    return int(GetWindowScaleDPI().x * value);
}



int main(int argc, char* argv[])
{
	// Initialization
	//--------------------------------------------------------------------------------------
	int screenWidth = 1280;
	int screenHeight = 800;

	SetConfigFlags(FLAG_MSAA_4X_HINT | FLAG_VSYNC_HINT | FLAG_WINDOW_RESIZABLE);
	InitWindow(screenWidth, screenHeight, "raylib-Extras [ImGui] example - simple ImGui Demo");
	SetTargetFPS(144);
	rlImGuiSetup(true);

	Texture image = LoadTexture("resources/parrots.png");

	// Main game loop
	while (!WindowShouldClose())    // Detect window close button or ESC key
	{
		BeginDrawing();
		ClearBackground(DARKGRAY);

		// start ImGui Conent
		rlImGuiBegin();

		// show ImGui Content
		bool open = true;
		ImGui::ShowDemoWindow(&open);

		open = true;
		if (ImGui::Begin("Test Window", &open))
		{
			ImGui::TextUnformatted(ICON_FA_JEDI);

			rlImGuiImage(&image);
		}
		ImGui::End();

		// end ImGui Content
		rlImGuiEnd();

		EndDrawing();
		//----------------------------------------------------------------------------------
	}
	rlImGuiShutdown();

	// De-Initialization
	//--------------------------------------------------------------------------------------   
    rlImGuiShutdown();
	UnloadTexture(image);
	CloseWindow();        // Close window and OpenGL context
	//--------------------------------------------------------------------------------------

	return 0;
}



/*
#include "Application.h"

int main(void)
{
    Application& render_lamp_app = Application::GetInstance();
    
    render_lamp_app.Init();
    render_lamp_app.Start();

    return 0;
}
*/