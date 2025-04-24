#ifndef ARCA_CONFIG_HPP
#define ARCA_CONFIG_HPP

//-------------------------------------------------------------------------------------------------------------------------------                                          	
//												RenderLamp - ArcaConfig
//                                      	Copyright (c) Márton Bán 2025
//
//	This class will store the given application's config datas
//-------------------------------------------------------------------------------------------------------------------------------

class ArcaConfig {
    public:
        ArcaConfig(const std::string& path);
    private:
        std::string mPath;
        std::map<std::string, std::any> configs;
};

ArcaConfig::ArcaConfig(const std::string& path) : mPath{path} {}

#endif
