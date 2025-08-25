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
     * @param instanceName name of the instance folder
     * @return true if it succested, false if failed 
    */
    inline bool InitArcaInstance(const std::string& instanceName) {
        return ArcaInstance::GetInstance().ArcaInstanceBuilder(instanceName);
    }

    /**
     * @brief Arca instance Mandotary meta data
     * @param applicationName Name of the application
     * @param applicationCreator Name of the Application Developer
     * @return true if it succested, false if failed 
    */
    inline void ArcaInstanceMetaDataSetup(const std::string& applicationName, const std::string& applicationCreator) {
        ArcaInstance::GetInstance().ApplicationDataSetup(applicationName, applicationCreator);
    }

    inline bool ArcaInstaceBuild() {
        return false;
    }

    inline void ArcaInstanceSave() {

    }

    //-----------------------------------------------------------------------------
    //                                  ARCA MODULES 
    //-----------------------------------------------------------------------------  

    //-----------------------------------------------------------------------------
    //                                  ARCA ASSETS
    //-----------------------------------------------------------------------------  
    
    //-----------------------------------------------------------------------------
    //                                 ARCA FILES
    //-----------------------------------------------------------------------------  

    //-----------------------------------------------------------------------------
    //                                 ARCA PATH SYSTEM 
    //-----------------------------------------------------------------------------  
    /**
     * @brief Create an ArcaPath Object from the ArcaInstance root directory
     * @param key referance to the path
     * @param path relative path
     * @return void but it will saved by the Arca Instance
    */
    inline void CreateArcaPath(const std::string& key, const std::filesystem::path& path) {
        
    }

    /**
     * @brief Create an ArcaPath Object from the ArcaInstance root directory
     * @param key referance to the path
     * @param path relative path
     * @return void but it will saved by the Arca Instance
    */
    inline void CreateArcaPath(const std::string& key, ArcaPath pathObject) {
        
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