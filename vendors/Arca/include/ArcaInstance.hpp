#ifndef ARCA_INSTACE_HPP
#define ARCA_INSTANE_HPP

#include <string>

#include "ArcaIO.hpp"

class ArcaInstance {
    public:
        static ArcaInstance& GetInstance() {
            static ArcaInstance instance;
            return instance;
        }
        bool IsFileExists(const std::string& fullFilePath);
    protected:
        ArcaInstance() = default;
    private:
        ArcaIO mArcaIO;
};

#endif