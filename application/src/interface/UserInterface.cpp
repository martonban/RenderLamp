#include "interface/UserInterface.hpp"

UserInterface::UserInterface() {

}

void UserInterface::Start() {
    PrintWelcome();
    ApplicationLoop();
}

void UserInterface::ApplicationLoop() {
    PrintMenu();
    //while (mApplicationRunabality) {
     //  
    //}
}