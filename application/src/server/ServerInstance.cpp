#include "server/ServerInstance.hpp"

ServerInstance::ServerInstance() {}

void ServerInstance::Init() {
    Arca::InitArcaInstance("RenderLamp");
    if(Arca::FetchArcaInstanceData()) {
        Arca::BuildArcaInstance();
        std::cout << "Arca instance has been de-serialized and build!" << std::endl;
    } else {
        Arca::CreateArcaInstance();
        Arca::AddCreator("Márton Bán");
        Arca::CreateModule("ProjectLists");
        if(Arca::ReleaseArcaInstance()) {
            std::cout << "Arca Instance has been created!" << std::endl;
        }
    }
}

void ServerInstance::Start() {
    mCliInterface = std::make_unique<CliInterface>(CLI_APP_VIEW);
    mServer = std::make_shared<Server>(mCliInterface->GetPrinter());
    mServer->Subscribe();
    mCliInterface->Run();
    mServer->Start();
}

ServerInstance* ServerInstance::mServerInstance = nullptr;

ServerInstance* ServerInstance::GetInstance() {
    if(mServerInstance == nullptr) {
        mServerInstance = new ServerInstance();
    }
    return mServerInstance;
}