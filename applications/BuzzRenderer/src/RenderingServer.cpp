#include "RenderingServer.hpp"

void RenderingServer::Init() {
    mUserInterface = std::make_unique<UserInterface>();
}

void RenderingServer::Start() {
    mUserInterface -> Start();
}