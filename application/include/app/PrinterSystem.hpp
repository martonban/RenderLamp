#ifndef PRINTER_SYSTEM_HPP
#define PRINTER_SYSTEM_HPP

#include <iostream>
#include <filesystem>
#include <string>

#include "CliUtils.hpp"


class PrinterSystem {
    public:
        PrinterSystem(const CliViewMode& mode);
        void PrinterSystemController(bool& appStatus);

        void PrintWelcomeScreen();
    private:
        CliAppScenes mCurrentScene;
        CliViewMode mViewMode;

        std::string mPrintBuffer;

        void MainMenuHandler();
        void PrintMainMenu();

        void ProgressBarHandler();
        void PrintRenderProgressBar(const int& x);

        void PrintErrosMessage(const int& logLevel, const std::string& msg);

};

#endif