//------------------------------------------------------------------------------------------------
//                                              Arca
//                                       Márton Bán (C) 2025
//	
//  Arca is a "I hate to develop this every time" libary. Handling application data, user data, 
//  assets, files, and errors
//------------------------------------------------------------------------------------------------

#ifndef ARCA_HPP
#define ARCA_HPP

#include <string>
#include <fstream>
#include <filesystem>

#include "ArcaInstance.hpp"

namespace Arca {

    //-----------------------------------------------------------------------------
    //                                  ARCA INSTANCE 
    //-----------------------------------------------------------------------------    
    /**
     * @brief Create an Arca instance
     * @param absolutePath absolute path for the workspace on your disk
     * @param folderName name of the workspce folder
     * @return true if it succested, false if failed 
    */
    inline bool ArcaInstanceBuilder(const std::string& instanceName) {
        return ArcaInstance::GetInstance().ArcaInstanceBuilder(instanceName);
    }

    //-----------------------------------------------------------------------------
    //                                  SIMPLE UTILS  
    //-----------------------------------------------------------------------------    
    /**
     * @brief Check if this file exist on your system or not
     * @param fullFilePath an std::string for the file path 
     * @return True if exists, False if not
    */
    inline bool IsFileExists(const std::filesystem::path& fullFilePath) {
        return ArcaInstance::GetInstance().IsFileExists(fullFilePath);
    }

    /**
     * @brief This function will create a directory on your system
     * @param path Absolute path for the new folder
     * @param folderName Name of the new folder name
     * @return True if it gets created. False if it does not
    */
    inline bool CreateFolder(const std::filesystem::path& path, const std::string& folderName) {
        return ArcaInstance::GetInstance().CreateFolder(path, folderName);
    }
}

#endif