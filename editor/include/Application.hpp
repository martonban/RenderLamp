//------------------------------------------------------------------------------------------------
//                                    RenderLamp - Application
//                                      Márton Bán (C) 2024
//	
//  Application is a singleton class responsible for initializing and start the key componetns of
//  this project. 
//------------------------------------------------------------------------------------------------

#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include <iostream>
#include <memory>

#include "Arca.hpp"

#include "systems/RealTimeRenderingSystem.hpp"
#include "systems/BuildSystem.hpp"

#include "Window.hpp"


class Application {
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
        std::unique_ptr<Window> editorWindow;
        std::unique_ptr<RealTimeRenderingSystem> renderer;
};

#endif