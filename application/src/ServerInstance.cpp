#include "ServerInstance.hpp"

void ServerInstance::Init() {
    mUserInterface = std::make_unique<UserInterface>();
}

void ServerInstance::Start() {
    mUserInterface -> Start();
}