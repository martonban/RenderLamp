#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <iostream>
#include "raylib.h"
#include "SphereMeshComponent.hpp"
#include "RenderingSystem.hpp"

class Window {
    public:
        Window (int width, int height) {
            mWindowHeight = height;
            mWindowHeight = width;
        }
        void Start();
    private:
        void Loop();
        void Close();

    private:
        int mWindowHeight;
        int mWindowWidth;

        RenderingSystem mRenderingSystem;
        Camera3D mCamera = {0};
};

#endif