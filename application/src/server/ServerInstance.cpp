#include "server/ServerInstance.hpp"

ServerInstance::ServerInstance() {}

void ServerInstance::Init() {
    Arca::InitArcaInstance("RenderLamp");
    if(Arca::IsArcaNew()) {
        Arca::ApplicationMetaData metaData { "RenderLamp", "Marton Ban", "v0.1" };
        Arca::AddMetaData(metaData);

        Arca::ModuleConfig serverModuleConfig {
            "Server",
            std::filesystem::path {},
            Arca::CORE_TYPE,
            Arca::READY_FOR_PROCESSING
        };

        Arca::ProcessModuleConfig(serverModuleConfig);
        Arca::AddModule(serverModuleConfig);
        Arca::Build();
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