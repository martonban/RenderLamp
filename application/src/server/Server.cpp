#include "server/Server.hpp"

Server::Server(std::weak_ptr<PrinterSystem> printer) {
    mPrinterPtr = printer;
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
    case 1:
        StartSession();
        break;
    
    default:
        break;
    }
}

void Server::StartSession() {
    std::cout << "Session Started" << std::endl;
}