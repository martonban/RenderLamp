#include "app/PrinterSystem.hpp"

#include <cmath>
#include <iomanip>

PrinterSystem::PrinterSystem(const CliViewMode& mode) {
    mViewMode = mode;
    mCurrentScene = MAIN_MENU;
}

void PrinterSystem::PrinterSystemController(bool& appStatus) {
    switch (mCurrentScene)
    {
    case MAIN_MENU:
        PrintMainMenu();
        MainMenuHandler();
        break;
    case RENDERING_PROGRESS_SCENE:
        ProgressBarHandler();
        break;
    case EXIT_SCENE:
        appStatus = false;
        break;
    default:
        break;
    }
}

void PrinterSystem::PrintWelcomeScreen() {
    std::cout << "\n \n" << std::endl;

    std::cout << ":::::::::  :::::::::: ::::    ::: :::::::::  :::::::::: :::::::::  :::            :::     ::::    ::::  :::::::::  " << std::endl;
    std::cout << ":+:    :+: :+:        :+:+:   :+: :+:    :+: :+:        :+:    :+: :+:          :+: :+:   +:+:+: :+:+:+ :+:    :+: " << std::endl;
    std::cout << "+:+    +:+ +:+        :+:+:+  +:+ +:+    +:+ +:+        +:+    +:+ +:+         +:+   +:+  +:+ +:+:+ +:+ +:+    +:+ " << std::endl;
    std::cout << "+#++:++#:  +#++:++#   +#+ +:+ +#+ +#+    +:+ +#++:++#   +#++:++#:  +#+        +#++:++#++: +#+  +:+  +#+ +#++:++#+  " << std::endl;
    std::cout << "+#+    +#+ +#+        +#+  +#+#+# +#+    +#+ +#+        +#+    +#+ +#+        +#+     +#+ +#+       +#+ +#+        " << std::endl;
    std::cout << "#+#    #+# #+#        #+#   #+#+# #+#    #+# #+#        #+#    #+# #+#        #+#     #+# #+#       #+# #+#        " << std::endl;
    std::cout << "###    ### ########## ###    #### #########  ########## ###    ### ########## ###     ### ###       ### ###   " << std::endl;
}

void PrinterSystem::MainMenuHandler() {
    bool validNumber = false;
    int chossenMenuPoint = 0;
    while (!validNumber) {
        bool s1, s2 = false;
        std::string input;
        std::cout << "> ";
        std::cin >> input;
        try {
            chossenMenuPoint = std::stoi(input);
            s1 = true;
        } catch (const std::invalid_argument& e) {
            s1 = false;
            PrintErrosMessage(3, "Not a number");
        }

        switch (chossenMenuPoint)
        {
        case 1:
            s2 = true;
            break;
        case 2:
            s2 = true;
            break;
        case 3:
            s2 = true;
            mCurrentScene = RENDERING_PROGRESS_SCENE;  
            break;
        case 4:
            s2 = true;
            mCurrentScene = EXIT_SCENE;
            break;
        default:
            s2 = false;
            PrintErrosMessage(3, "Not a menu point");
            break;
        }

        validNumber = s1 && s2;
    }
}

void PrinterSystem::PrintMainMenu() {
    std::cout << "\n" << std::endl;
    std::cout << "Main Menu" << std::endl;
    std::cout << "--------------------------------------------------------------------------------------" << std::endl;
    std::cout << "1 - Add New Project" << std::endl;
    std::cout << "2 - Load Project" << std::endl;
    std::cout << "3 - Render Test Scene" << std::endl; 
    std::cout << "4 - Exit" << std::endl;
    std::cout << "--------------------------------------------------------------------------------------" << std::endl;
}


void PrinterSystem::ProgressBarHandler() {
    constexpr int totalSteps = 300;
    int lastBucket = -1;

    for (int step = 1; step <= totalSteps; ++step) {
        volatile double accumulator = 0.0;
        for (int i = 0; i < 50000; ++i) {
            accumulator += std::sin((step + i) * 0.0001) * std::cos((step + i) * 0.0002);
        }

        const int percent = (step * 100) / totalSteps;
        int x = percent / 5;
        if (x > 20) {
            x = 20;
        }

        if (x != lastBucket) {
            PrintRenderProgressBar(x);
            lastBucket = x;
        }
    }

    PrintRenderProgressBar(20);
    std::cout << std::endl;
    mCurrentScene = MAIN_MENU;
}

void PrinterSystem::PrintRenderProgressBar(const int& x) {
    constexpr int barWidth = 20;
    int clampedX = x;

    if (clampedX < 0) {
        clampedX = 0;
    }

    if (clampedX > barWidth) {
        clampedX = barWidth;
    }

    const std::string done(clampedX, '#');
    const std::string remaining(barWidth - clampedX, '-');


    std::cout << "\r[" << done << remaining << "] "
              << std::setw(3) << (clampedX * 5) << "%" << std::flush;
}

void PrinterSystem::PrintErrosMessage(const int& logLevel, const std::string& msg) {
    switch (logLevel)
    {
    case 1:
        std::cerr << "ERROR: " << msg << std::endl;
        break;
    case 2:
        std::cerr << "WARNING: " << msg << std::endl;
        break;
    case 3:
        std::cerr << msg << std::endl;
        break;
    default:
        std::cerr << "Something went really wroing in the logging" << std::endl;
        break;
    }
}