#include "interface/UserInterface.hpp"

UserInterface::UserInterface() {
    mPrinter = std::make_unique<Printer>();
}

void UserInterface::Start() {
    mPrinter -> PrintWelcome();
}