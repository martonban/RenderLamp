#ifndef ARCA_HPP
#define ARCA_HPP

#include <string>
#include <fstream>

#include "ArcaInstance.hpp"

namespace Arca {
    //-----------------------------------------------------------------------------
    //                              ARCA INSTANCE SETTING 
    //-----------------------------------------------------------------------------    


    //-----------------------------------------------------------------------------
    //                                  SIMPLE UTILS  
    //-----------------------------------------------------------------------------    
    /**
     * @brief Check if this file exist on your system or not
     * @param fullFilePath an std::string for the file path 
     * @return True if exists, False if not
    */
    inline bool IsFileExists(const std::string& fullFilePath) {
        return ArcaInstance::GetInstance().IsFileExists(fullFilePath);
    }

    /**
     * @brief This function will create a directory on your system
     * @param path Absolute path for the new folder
     * @param folderName Name of the new folder name
     * @return True if it gets created. False if it does not
    */
    inline bool CreateFolder(const std::string& path, const std::string& folderName) {
        return ArcaInstance::GetInstance().CreateFolder(path, folderName);
    }

    //-----------------------------------------------------------------------------
    //                                 I/O UTILS 
    //-----------------------------------------------------------------------------    
    



    //-----------------------------------------------------------------------------
    //                              SERILAZATION UTILS
    //-----------------------------------------------------------------------------    


}

#endif