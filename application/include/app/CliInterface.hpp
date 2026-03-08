#ifndef CLI_INTERFACE_HPP
#define CLI_INTERFACE_HPP

#include <memory>

#include "PrinterSystem.hpp"
#include "CliUtils.hpp"


class CliInterface {
    public:
        CliInterface(const CliViewMode& mode);
    private:
        void StartAppViewLoop();
        CliViewMode mViewMode;
        bool mAppStatus = false;
};

#endif