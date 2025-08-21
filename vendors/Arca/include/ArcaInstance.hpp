#ifndef ARCA_INSTANCE_HPP
#define ARCA_INSTANCE_HPP

#include <string>
#include <memory>

#include "ArcaIO.hpp"
#include "WorkspaceType.hpp"

class ArcaInstance {
    public:
        // Insntace Realted Funtions
        static ArcaInstance& GetInstance() {
            static ArcaInstance instance;
            return instance;
        }
        bool CreateInstance(const std::string& instanceName);

        // ArcaIO Functions
        bool IsFileExists(const std::string& fullFilePath);
        bool CreateFolder(const std::string& path, const std::string& folderName);
    protected:
        ArcaInstance() = default;
    private:
        ArcaInstance(const ArcaInstance&) = delete;
        ArcaInstance& operator=(const ArcaInstance&) = delete;
        
        bool mIsSetuped = false;
        ArcaIO mArcaIO;
};

#endif