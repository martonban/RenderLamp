#ifndef ARCA_CONFIG_HPP
#define ARCA_CONFIG_HPP

//-------------------------------------------------------------------------------------------------------------------------------                                          	
//												RenderLamp - ArcaConfig
//                                      	Copyright (c) Márton Bán 2025
//	This is class will 
//-------------------------------------------------------------------------------------------------------------------------------

class ArcaConfig {
    public:
        ArcaConfig(const std::string& path);
    private:
        std::string mPath;
};

ArcaConfig::ArcaConfig(const std::string& path) : mPath{path} {}

#endif
