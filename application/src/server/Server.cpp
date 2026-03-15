#include "server/Server.hpp"

Server::Server(std::weak_ptr<PrinterSystem> printer) {
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

void Server::AddNewProject(const std::filesystem::path& path) {
    std::string name = path.filename().string();
    std::shared_ptr<ArcaModule> projectModule = Arca::GetArcaModule("ProjectLists");
    std::string projectListConfigFileName = "RenderProjects";
    projectModule->CreateNewContainer(projectListConfigFileName);
    projectModule->GetContainer(projectListConfigFileName)->AddPair(name, path);
    projectModule->GetContainer(projectListConfigFileName)->Dispatch();
    projectModule->Serialize();
}

void Server::StartSession() {
    std::cout << "Session Started" << std::endl;
}