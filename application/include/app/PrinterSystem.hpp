#ifndef PRINTER_SYSTEM_HPP
#define PRINTER_SYSTEM_HPP

#include <iostream>
#include <filesystem>
#include <string>
#include <vector>
#include <cmath>
#include <iomanip>
#include <algorithm>
#include <cctype>

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
        void SetProjectList(const std::vector<std::pair<std::string, std::filesystem::path>>& projects);
    private:
        std::vector<std::weak_ptr<IObserver>> mObserverVector;
        std::vector<std::pair<std::string, std::filesystem::path>> mProjects;
        ServerRequest mServerRequest {};
        CliAppScenes mCurrentScene;
        CliViewMode mViewMode;


        std::string mPrintBuffer;

        void MainMenuHandler();
        void PrintMainMenu();

        void AddNewProjectHandler();
        bool PathValidator(const std::string& path);
        std::string CleanInput(const std::string& path);

        void ListAllProjectHadler();
       

        void RenderProjectHandler();


        void ProgressBarHandler();
        void PrintRenderProgressBar(const int& x);

        void PrintErrosMessage(const int& logLevel, const std::string& msg);

};

#endif