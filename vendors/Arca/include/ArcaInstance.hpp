#ifndef ARCA_INSTANCE_HPP
#define ARCA_INSTANCE_HPP

#include <string>

#include "ArcaIO.hpp"

class ArcaInstance {
    public:
        static ArcaInstance& GetInstance() {
            static ArcaInstance instance;
            return instance;
        }
        bool IsFileExists(const std::string& fullFilePath);
        bool CreateFolder(const std::string& path, const std::string& folderName);
    protected:
        ArcaInstance() = default;
    private:
        ArcaInstance(const ArcaInstance&) = delete;
        ArcaInstance& operator=(const ArcaInstance&) = delete;
        ArcaIO mArcaIO;
};

#endif