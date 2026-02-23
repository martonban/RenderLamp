#include "interface/Printer.hpp"
#include "ServerInstance.hpp"
#include "Arca.hpp"

int main() {
    // TODO::ARCA INSTACE LATER
    Arca::InitArcaInstance("BuzzRenderer");
    if(Arca::FetchArcaInstanceData()) {
        Arca::BuildArcaInstance();
        std::cout << "Arca instance has been de-serialized and build!" << std::endl;
    } else {
        Arca::CreateArcaInstance();
        Arca::AddCreator("Márton Bán");
        Arca::CreateModule("Editor");
        Arca::CreateModule("Renderer");
        if(Arca::ReleaseArcaInstance()) {
            std::cout << "Arca Instance has been created!" << std::endl;
        }
    }

    // Singleton Application
    ServerInstance& renderingServerInstance = ServerInstance::GetInstance();
    renderingServerInstance.Init();
    renderingServerInstance.Start();

    char c;
    std::cin >> c;
    return 0;
}