#include "RenderingServer.hpp"

void RenderingServer::Init() {
    mPrinter = std::make_unique<Printer>();
}

void RenderingServer::Start() {
   mPrinter->PrintWelcome();
}