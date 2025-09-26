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
     * @brief Initializes and starts the Arca Libary with the specified application name.
     * 
     * This function serves as a convenient wrapper for the singleton ArcaInstance's
     * StartArcaInstance method. It initializes the Arca Libary for the application.
     * 
     * @param applicationName The name of the application to be used within Arca
     * @return void
     */
    inline void InitArcaInstance(const std::string& applicationName) {
        ArcaInstance::GetInstance().StartArcaInstance(applicationName);
    }

    /**
     * @brief This function will going to fetch all data from the instance serialzation file.
     * 
     * Note: This function is not going to merit a fully functional Arca Instance! If you need this use Arca::Build();
     * @param 
     * @return A bool value based on the file existance.
    */
    inline bool FetchArcaInstance() {
        return ArcaInstance::GetInstance().InstanceDeserialize();
    }
   
    /**
     * @brief This function will trigger all the Arca components based on the ArcaInstance file
     * @param 
     * @return
    */
    inline bool BuildArcaInstance() {
        return false;
    }

    /**
     * @brief This function will create the folder structure for ArcaFiles
     * @param 
     * @return void
    */
    inline void CreateArcaInstance() {
        ArcaInstance::GetInstance().CreateArcaInstance();
    }
    
    /**
     * @brief Add extra metadata for the application
     * @param creatorName an std::string for the creators
     * @return void
    */
    inline void AddCreator(const std::string& creatorName) {
        ArcaInstance::GetInstance().AddCreator(creatorName);
    }

    /**
     * @brief Once all data has been received, the Arca Instance saves its state and generates the metadata files.
     * @param 
     * @return
    */
    inline bool ReleaseArcaInstance() {
        return ArcaInstance::GetInstance().InstanceSerialize();
    }


    inline void ArcaTest() {
        ArcaInstance::GetInstance().ArcaTest();
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