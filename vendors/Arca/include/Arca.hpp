#ifndef ARCA_HPP
#define ARCA_HPP

#include <string>

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

    inline bool CreateFolder(const std::string& path, const std::string& folderName) {
        return ArcaInstance::GetInstance().CreateFolder(path, folderName);
    }


    //-----------------------------------------------------------------------------
    //                              SERILAZATION UTILS
    //-----------------------------------------------------------------------------    


}

#endif