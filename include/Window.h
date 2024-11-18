#ifndef WINDOW_H
#define WINDOW_H

#include "raylib.h"
#include <iostream>

class Window {
    // Functions
    public:
        Window(int width, int height) {
            window_height = height;
            window_width = width;
        }
        void Start();
    private:
        void Loop();
        void Close();

    // Data fields
    private:
        // Basic properties for the window
        int window_height;
        int window_width;

        Camera3D camera = { 0 };
        Vector3 cubePosition = { 0.0f, 0.0f, 0.0f };
};

#endif