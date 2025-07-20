#include "RenderingSystem.hpp"
RenderingSystem::RenderingSystem(const int& framebufferWidth, const int& framebufferHeight) : mFramebufferWidth(framebufferWidth), mFramebufferHeight(framebufferHeight) {
    // Camera
    mCamera.position = { 10.0f, 10.0f, 10.0f }; 
    mCamera.target = { 0.0f, 0.0f, 0.0f };
    mCamera.up = { 0.0f, 1.0f, 0.0f };
    mCamera.fovy = 45.0f;
    mCamera.projection = CAMERA_PERSPECTIVE;
}

void RenderingSystem::RenderingAllocation() {
    // FrameBuffer
    mRenderTarget = LoadRenderTexture(mFramebufferWidth, mFramebufferHeight);
}

void RenderingSystem::Render() {
    BeginTextureMode(mRenderTarget);
    ClearBackground(RAYWHITE);
        BeginMode3D(mCamera);
            DrawCube({0.f, 0.f, 0.f}, 2.0f, 2.0f, 2.0f, RED);
            DrawGrid(10, 1.0f);
        EndMode3D();
	EndTextureMode();
}

void RenderingSystem::DestroyRenderer() {
    UnloadRenderTexture(mRenderTarget);
}

void RenderingSystem::DrawFramebuffer() {
    DrawTextureRec(mRenderTarget.texture, Rectangle{0, 0, (float)mRenderTarget.texture.width, -(float)mRenderTarget.texture.height}, Vector2{0, 0}, WHITE);
}
