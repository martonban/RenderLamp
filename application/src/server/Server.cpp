#include "server/Server.hpp"

Server::Server(std::weak_ptr<PrinterSystem> printer) {
    mPrinterPtr = printer;
}

void Server::Start() {
    Arca::CreateModule("Server");
    if(Arca::ReleaseArcaInstance()) {
        std::cout << "Arca Instance has been created!" << std::endl;
    }
}

void Server::Subscribe() {
    auto printer = mPrinterPtr.lock();
    if (!printer) {
        return;
    }

    printer->Attach(std::static_pointer_cast<IObserver>(shared_from_this()));
}

void Server::Update(const ServerRequest& request) {
    switch (request.type)
    {
    case ADD_NEW_PROJECT:
        AddNewProject(request.path);
        break;
    default:
        break;
    }
}


void Server::AddNewProject(const std::filesystem::path& path) {
    std::cout << "PINA" << std::endl;
}

void Server::StartSession() {
    std::cout << "Session Started" << std::endl;
}