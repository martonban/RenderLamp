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
#include "systems/scene/models/Scene.hpp"
#include "systems/scene/SceneManagerSystem.hpp"
#include "systems/scene/models/Entity.hpp"
#include "systems/scene/models/Component.hpp"


class Window {
    public:
        Window (int width, int height) {
            mWindowHeight = height;
            mWindowWidth = width;
        }
        void Init();
        void Start();
    private:
        void MainLoop();
        void Close();
    private:
        int mWindowHeight;
        int mWindowWidth;
        Scene* mCurrentScene = nullptr;
};

#endif