#ifndef PRINTER_SYSTEM_HPP
#define PRINTER_SYSTEM_HPP

#include <iostream>
#include <filesystem>
#include <string>
#include <vector>
#include <cmath>
#include <iomanip>

#include "CliUtils.hpp"
#include "interfaces/ISubject.hpp"
#include "server/ServerRequest.hpp"

class PrinterSystem : public ISubject {
    public:
        PrinterSystem(const CliViewMode& mode);
        void PrinterSystemController(bool& appStatus);
        void Attach(std::weak_ptr<IObserver> observer) override;
        void Detach(std::weak_ptr<IObserver> observer) override;
        void Notify() override;

        void PrintWelcomeScreen();
    private:
        std::vector<std::weak_ptr<IObserver>> mObserverVector;
        ServerRequest mServerRequest {};
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