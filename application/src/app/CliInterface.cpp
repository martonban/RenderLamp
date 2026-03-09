#include "app/CliInterface.hpp"

CliInterface::CliInterface(const CliViewMode& mode) {
    mViewMode = mode;
    mPrinter = std::make_shared<PrinterSystem>(mode);
}

void CliInterface::Run() {
    switch (mViewMode)
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

std::weak_ptr<PrinterSystem> CliInterface::GetPrinter() const noexcept {
    return mPrinter;
}

void CliInterface::StartAppViewLoop() {
    mPrinter -> PrintWelcomeScreen();
    while(mAppStatus) {
        mPrinter->PrinterSystemController(mAppStatus);
    }
}