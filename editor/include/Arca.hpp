#ifndef ARCA_HPP
#define ARCA_HPP

//-------------------------------------------------------------------------------------------------------------------------------                                          	
//												 RenderLamp - Arca
//                                      	Copyright (c) Márton Bán 2025
//
//  Arca is part of mine own C++ framework I am developping in the background. Currently this is just a experimenting system 
//
//  If you create an application Arca will 
//-------------------------------------------------------------------------------------------------------------------------------

#include <iostream>
#include <string>

#include "ArcaIO.hpp"


class Arca {
    public:
        Arca();
        void CreateDirectory(const std::string& path, const std::string& name);
    private:
        // Instances 
        ArcaIO arcaIO{};
        std::string GetAppDataPath(); 
};


#endif

