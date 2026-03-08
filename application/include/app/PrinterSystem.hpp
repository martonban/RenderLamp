#ifndef PRINTER_SYSTEM_HPP
#define PRINTER_SYSTEM_HPP

#include <iostream>

#include "CliUtils.hpp"


class PrinterSystem {
    public:
        PrinterSystem(const CliViewMode& mode);
        void PrintCurrentState();
        void WaitForUserInput(const std::string& userInput);
    private:
        CliAppScenes mCurrentScene;
        CliViewMode mViewMode;
        std::string mPrintBuffer;

        void PrintWelcomeScreen();
};

#endif