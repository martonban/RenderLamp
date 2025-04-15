#ifndef ARCA_HPP
#define ARCA_HPP

//-------------------------------------------------------------------------------------------------------------------------------*                                          	
//												RenderLamp - Arca
//                                      	Copyright (c) Márton Bán 2025
//	This is the prototype version of my own asset manager libary ARCA. If the libary is ready this class will be
// the wrapper for the libary.
//-------------------------------------------------------------------------------------------------------------------------------

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

class Arca {
    public:
        Arca(const std::string& endOfPath);
    private:
        std::string m_arcaInstanceFilePath;
        std::string m_configFilePath;
        std::string m_sceneManagerFilePath;
        std::string m_sceneBankFilePath;
        void FetchArcaInstacePaths();
        std::string GetAppDataPath(); 
};

#endif

// 
inline Arca::Arca(const std::string& endOfPath) {
    m_arcaInstanceFilePath = GetAppDataPath() + endOfPath;
    std::cout << m_arcaInstanceFilePath << std::endl;
    FetchArcaInstacePaths();
}

// Fetch ArcaInstance.txt wich will store the crucial dependencies file path   
inline void Arca::FetchArcaInstacePaths() {
    std::ifstream file(m_arcaInstanceFilePath);
    if (!file.is_open()) {
        std::cerr << "Error: The file is not existing! \n";
        return;
    }

    std::string line;
    if (std::getline(file, line)) {
        std::stringstream ss(line);
        std::getline(ss, m_configFilePath, ';');
        std::getline(ss, m_sceneManagerFilePath, ';');
        std::getline(ss, m_sceneBankFilePath, ';');
    } else {
        std::cerr << "Error: The file is not valid! \n";
    }

    file.close();
}

// TODO: Make it more elegant 
inline std::string Arca::GetAppDataPath() {
    return "C:/Users/Marci/AppData/Roaming/Arca";
}