
#include "app/PrinterSystem.hpp"

PrinterSystem::PrinterSystem(const CliViewMode& mode) {
    mViewMode = mode;
    mCurrentScene = WELCOME_SCREEN;
}

void PrinterSystem::PrintCurrentState() {
    PrintWelcomeScreen();
    /*
    switch (mCurrentScene)
    {
    case WELCOME_SCREEN:
        PrintWelcomeScreen();
        break;
    
    default:
        break;
    }
    */
}

void PrinterSystem::WaitForUserInput(const std::string& userInput) {
    // TODO: Implement user input handling
}


void PrinterSystem::PrintWelcomeScreen() {
    std::cout << "\n \n \n \n" << std::endl;

    std::cout << ":::::::::  :::::::::: ::::    ::: :::::::::  :::::::::: :::::::::  :::            :::     ::::    ::::  :::::::::  " << std::endl;
    std::cout << ":+:    :+: :+:        :+:+:   :+: :+:    :+: :+:        :+:    :+: :+:          :+: :+:   +:+:+: :+:+:+ :+:    :+: " << std::endl;
    std::cout << "+:+    +:+ +:+        :+:+:+  +:+ +:+    +:+ +:+        +:+    +:+ +:+         +:+   +:+  +:+ +:+:+ +:+ +:+    +:+ " << std::endl;
    std::cout << "+#++:++#:  +#++:++#   +#+ +:+ +#+ +#+    +:+ +#++:++#   +#++:++#:  +#+        +#++:++#++: +#+  +:+  +#+ +#++:++#+  " << std::endl;
    std::cout << "+#+    +#+ +#+        +#+  +#+#+# +#+    +#+ +#+        +#+    +#+ +#+        +#+     +#+ +#+       +#+ +#+        " << std::endl;
    std::cout << "#+#    #+# #+#        #+#   #+#+# #+#    #+# #+#        #+#    #+# #+#        #+#     #+# #+#       #+# #+#        " << std::endl;
    std::cout << "###    ### ########## ###    #### #########  ########## ###    ### ########## ###     ### ###       ### ###   " << std::endl;
}