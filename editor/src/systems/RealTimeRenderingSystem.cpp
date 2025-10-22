#include "systems/RealTimeRenderingSystem.hpp"
#include <fstream>

RealTimeRenderingSystem::RealTimeRenderingSystem(const int& framebufferWidth, const int& framebufferHeight) : 
        mFramebufferWidth(framebufferWidth), mFramebufferHeight(framebufferHeight) {
    // Camera
    mCamera.position = { 10.0f, 10.0f, 10.0f }; 
    mCamera.target = { 0.0f, 0.0f, 0.0f };
    mCamera.up = { 0.0f, 1.0f, 0.0f };
    mCamera.fovy = 45.0f;
    mCamera.projection = CAMERA_PERSPECTIVE;
}
void RealTimeRenderingSystem::RenderingAllocation() {
    // FrameBuffer
    mRenderTarget = LoadRenderTexture(mFramebufferWidth, mFramebufferHeight);
    sp.Start();
}


void RealTimeRenderingSystem::Render() {
    BeginTextureMode(mRenderTarget);
    ClearBackground(RAYWHITE);
        BeginMode3D(mCamera);
        if(IsKeyPressed(KEY_A)) {
            nlohmann::json instanceJson = sp.ToSceneJson();
            std::ofstream file("C:/Project/gg.json");
            file << instanceJson.dump(4);
            file.close();
        }
            //DrawCube({0.f, 0.f, 0.f}, 2.0f, 2.0f, 2.0f, RED);
            sp.Tick();
            DrawGrid(10, 1.0f);
        EndMode3D();
	EndTextureMode();
}

void RealTimeRenderingSystem::DestroyRenderer() {
    UnloadRenderTexture(mRenderTarget);
}

void RealTimeRenderingSystem::DrawFramebuffer() {
    DrawTextureRec(mRenderTarget.texture, Rectangle{0, 0, (float)mRenderTarget.texture.width, -(float)mRenderTarget.texture.height}, Vector2{0, 0}, WHITE);
}
