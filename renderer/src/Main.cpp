#include "interface/Printer.hpp"
#include "ServerInstance.hpp"

int main() {
    // TODO::ARCA INSTACE LATER

    // Singleton Application
    ServerInstance& renderingServerInstance = ServerInstance::GetInstance();
    renderingServerInstance.Init();
    renderingServerInstance.Start();

    char c;
    std::cin >> c;
    return 0;
}