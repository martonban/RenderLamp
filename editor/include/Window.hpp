#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <iostream>
#include "raylib.h"
#include "SphereMeshComponent.hpp"

class Window {
    // Functions
    public:
        Window (int width, int height) {
            window_height = height;
            window_width = width;
        }
        void Start();
    private:
        void Loop();
        void Close();

    private:
        int window_height;
        int window_width;
        SphereMeshComponent sp { {0, 0, 0}, 1.0f };
        Camera3D camera = {0};
};

#endif