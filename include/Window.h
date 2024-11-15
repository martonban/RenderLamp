#ifndef WINDOW_H
#define WINDOW_H

#include <vector>

#include "WindowComponent.h"

class Window {
    // Functions
    public:
        Window(const char* window_defination_file);
        void Start();
    private:
        void FetchData();
        bool FatchValidator();

    // Data fields
    private:
        // Basic properties for the window
        int window_height;
        int window_width;
        const char* window_title;

        const char* configuration_file;
        
        // Window Component System
        std::vector<WindowComponent> component_vector;
};

#endif