//------------------------------------------------------------------------------------------------
//                                    RenderLamp - Application
//                                      Márton Bán (C) 2024
//	
//  Application is a singleton class responsible for initializing and start the key componetns of
//  this project. 
//
//  TODO: Initialize Arca Global Instance 
//------------------------------------------------------------------------------------------------

#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include <iostream>

#include "RenderingSystem.hpp"
#include "Window.hpp"


class Application {
    // Functions
    public:
        void Init();
        void Start();
        static Application& GetInstance() {
            static Application instance;
            return instance;
        }
    protected:
        Application() = default;
    private:
};

#endif