#include "server/Server.hpp"

Server::Server(std::weak_ptr<PrinterSystem> printer) {
    Arca::ModuleConfig config = Arca::GetModule("Server");
    mArcaModule = std::make_shared<Arca::Module>(config);
    mArcaModule->AddAccessPoint("TestRender", std::filesystem::absolute("./assets/TestRender"));
    mArcaModule->Save();
    mPrinterPtr = printer;
}

void Server::Start() {
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

void Server::AddNewProject(const std::filesystem::path& inputPath) {
    std::string name = inputPath.filename().string();
    std::filesystem::path path = std::filesystem::absolute(inputPath);

    mArcaModule->AddAccessPoint(name, path);
    mArcaModule->Save();
}

void Server::StartSession() {
    std::cout << "Session Started" << std::endl;
}