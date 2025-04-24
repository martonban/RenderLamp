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

#include <map>
#include <any>
#include <string>

#include <fstream>
#include <sstream>


#include <nlohmann/json.hpp>
using json = nlohmann::json;


#include "ArcaFileHandler.hpp"
#include "ArcaConfig.hpp"

class Arca {
    public:
        Arca(const std::string& endOfPath);
    private:
        // Instances
        ArcaConfig m_arcaConfig {""};
        // Data fields
        std::string m_projectPath;
        // Helper Functions
        std::string GetAppDataPath(); 
};


//-------------------------------
//      ARCA API FUNCTIONS
//-------------------------------

// To create an Arca Instance you need the file
Arca::Arca(const std::string& endOfPath) {
    m_projectPath = GetAppDataPath() + endOfPath;

}


//-------------------------------
//     ARCA Helper Functions
//-------------------------------

// TODO: Make it more elegant 
std::string Arca::GetAppDataPath() {
    return "C:/Users/Marci/AppData/Roaming/Arca";
}

#endif

