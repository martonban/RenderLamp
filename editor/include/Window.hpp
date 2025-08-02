//------------------------------------------------------------------------------------------------
//                                      RenderLamp - Window
//                                      Márton Bán (C) 2024
//	
// The Window class is responsible for displaying the viewport and GUI to the user, as well as 
//  handling all the mouse and keyboard inputs. 
//
//  Note: this project is follows  a tree-like structure. Thus the SceneManager component is
//  initalized at this class, since both the rendering system and the ECS share the same hiearchy 
//
//  TODO: - RenderingSystem
//        - SceneManager
//        - GUI Layer
//        - KeyListener
//        - Mouse Listener
//------------------------------------------------------------------------------------------------

#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <iostream>
#include "raylib.h"
#include "RenderingSystem.hpp"

class Window {
    public:
        Window (int width, int height) {
            mWindowHeight = height;
            mWindowWidth = width;
        }
        void Start();
        void AttachRenderer(RenderingSystem& renderer);
    private:
        void WindowLoop();
        void Close();

    private:
        int mWindowHeight;
        int mWindowWidth;
        RenderingSystem* mRenderer = nullptr;
};

#endif