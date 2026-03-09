#include "app/CliInterface.hpp"

CliInterface::CliInterface(const CliViewMode& mode) {
    mViewMode = mode;
    switch (mode)
    {
    case CLI_APP_VIEW:
        mAppStatus = true;
        StartAppViewLoop();
        break;
    case SERVER_VIEW:
        // TO-DO Implement this case
        // StartServerListener();
        break;
    default:
        break;
    }
}

void CliInterface::StartAppViewLoop() {
    auto printer = std::make_unique<PrinterSystem>(mViewMode);
    printer -> PrintWelcomeScreen();
    while(mAppStatus) {
        printer->PrinterSystemController(mAppStatus);
    }
}