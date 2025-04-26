#ifndef ARCA_HPP
#define ARCA_HPP

//-------------------------------------------------------------------------------------------------------------------------------                                          	
//												 RenderLamp - Arca
//                                      	Copyright (c) Márton Bán 2025
//
//  Arca is a subsystem of RenderLamp. Arca will handle of the application and user data, with a simple Interface
//-------------------------------------------------------------------------------------------------------------------------------

#include <iostream>
#include <string>

#include "ArcaIO.hpp"


class Arca {
    public:
        Arca(const std::string& applicationName);
        void CreateDirectory(const std::string& path, const std::string& name);
    private:
        // Instances 
        ArcaIO arcaIO{};
        std::string GetAppPath(); 
};


#endif

