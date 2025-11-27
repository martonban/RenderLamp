#include "interface/Printer.hpp"
#include "RenderingServer.hpp"


int main() {
    // TODO::ARCA INSTACE LATER


    // Singleton Application
    RenderingServer& renderingServerInstance = RenderingServer::GetInstance();
    renderingServerInstance.Init();
    renderingServerInstance.Start();
    
    char c;
    std::cin >> c;
    return 0;
}