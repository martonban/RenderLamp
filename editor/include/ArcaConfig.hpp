#ifndef ARCA_CONFIG_HPP
#define ARCA_CONFIG_HPP

//-------------------------------------------------------------------------------------------------------------------------------                                          	
//												 RenderLamp - ArcaConfig
//                                      	Copyright (c) Márton Bán 2025
//
//  This class will store config datas from a file 
//-------------------------------------------------------------------------------------------------------------------------------

#include <iostream>
#include <string>
#include <map>


#include "ArcaIO.hpp"

class ArcaConfig {
    public:
        ArcaConfig(const std::string& cofigFilePath);
        void AddValue(const std::string& key, const std::string& value);
        std::string GetStringValue(const std::string& key);
        float GetFloatValue(const std::string& key);
        int GetIntValue(const std::string& key);
    private:
        ArcaIO arcaIO {};
        std::map<std::string, std::string> mConfigData;
};



#endif