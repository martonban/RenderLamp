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
     * @brief If Arca has been created before this line of code will fetch the existing data
     * @return true if it succested, false if failed 
    */
    inline void StartArcaInstance(const std::string& applicationName) {
        ArcaInstance::GetInstance().StartArcaInstance(applicationName);
    }

    /**
     * @brief Check if this file exist on your system or not
     * @param fullFilePath an std::string for the file path 
     * @return True if exists, False if not
    */
    inline bool BuildArcaInstance() {
        return false;
    }

    /**
     * @brief Check if this file exist on your system or not
     * @param fullFilePath an std::string for the file path 
     * @return True if exists, False if not
    */
    inline void CreateArcaInstance() {
        ArcaInstance::GetInstance().CreateArcaInstance();
    }
    
    /**
     * @brief Check if this file exist on your system or not
     * @param fullFilePath an std::string for the file path 
     * @return True if exists, False if not
    */
    inline void AddCreator(const std::string& creatorName) {
        ArcaInstance::GetInstance().AddCreator(creatorName);
    }

    /**
     * @brief Check if this file exist on your system or not
     * @param fullFilePath an std::string for the file path 
     * @return True if exists, False if not
    */
    inline bool InstanceSerialize() {
        return ArcaInstance::GetInstance().InstanceSerialize();
    }


    //-----------------------------------------------------------------------------
    //                                  ARCA Module
    //----------------------------------------------------------------------------- 
        /**
     * @brief Check if this file exist on your system or not
     * @param fullFilePath an std::string for the file path 
     * @return True if exists, False if not
    */
    inline void CreateModule(const std::filesystem::path& moduleName) {
        return ArcaInstance::GetInstance().CreateModule(moduleName);
    }

    //-----------------------------------------------------------------------------
    //                               SIMPLE I/O UTILS  
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