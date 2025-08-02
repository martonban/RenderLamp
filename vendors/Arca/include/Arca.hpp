#ifndef ARCA_HPP
#define ARCA_HPP

#include <string>

#include "ArcaInstance.hpp"

namespace Arca {
    inline bool IsFileExists(const std::string& fullFilePath) {
        return ArcaInstance::GetInstance().IsFileExists(fullFilePath);
    }
}

#endif