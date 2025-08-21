//-----------------------------------------------------------------------------
//                              RenderLamp - ArcaIO
//
//  This class is responsible for file handleing.
//-----------------------------------------------------------------------------

#ifndef ARCA_IO_HPP
#define ARCA_IO_HPP

#include <iostream>
#include <fstream>
#include <filesystem>
#include <sys/stat.h>


#include <string>
#include <map>

#include <nlohmann/json.hpp>
using json = nlohmann::json;


class ArcaIO {
    public:
        bool IsFileExists(const std::string& fullFilePath);
        bool CreateFolder(const std::string& path, const std::string& name);
        bool IsDirectoryExists(const std::string& path);

};



#endif