//------------------------------------------------------------------------------------------------
//                                      RenderLamp - Window
//                                      Márton Bán (C) 2024
//	
// The Window class is responsible for displaying the viewport and GUI to the user, as well as 
//  handling all the mouse and keyboard inputs. 
//
//------------------------------------------------------------------------------------------------

#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <iostream>
#include <memory>
#include "raylib.h"
#include "systems/RealTimeRenderingSystem.hpp"

class Window {
    public:
        Window (int width, int height) {
            mWindowHeight = height;
            mWindowWidth = width;
        }
        void Start();
        void AttachRenderer(std::unique_ptr<RealTimeRenderingSystem> renderer);
    private:
        void WindowLoop();
        void Close();

    private:
        int mWindowHeight;
        int mWindowWidth;
        std::unique_ptr<RealTimeRenderingSystem> mRenderer;
};

#endif