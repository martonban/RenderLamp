#include "systems/RealTimeRenderingSystem.hpp"

RealTimeRenderingSystem::RealTimeRenderingSystem(const int& framebufferWidth, const int& framebufferHeight, std::unique_ptr<SceneManagerSystem>) : 
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
}

void RealTimeRenderingSystem::Render() {
    BeginTextureMode(mRenderTarget);
    ClearBackground(RAYWHITE);
        BeginMode3D(mCamera);
            DrawCube({0.f, 0.f, 0.f}, 2.0f, 2.0f, 2.0f, RED);
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
