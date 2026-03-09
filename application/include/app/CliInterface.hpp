#ifndef CLI_INTERFACE_HPP
#define CLI_INTERFACE_HPP

#include <memory>

#include "PrinterSystem.hpp"
#include "CliUtils.hpp"


class CliInterface {
    public:
        CliInterface(const CliViewMode& mode);
        std::weak_ptr<PrinterSystem> GetPrinter() const noexcept;
        void Run();
        
    private:
        void StartAppViewLoop();

        std::shared_ptr<PrinterSystem> mPrinter; 
        CliViewMode mViewMode;
        bool mAppStatus = false;
};

#endif