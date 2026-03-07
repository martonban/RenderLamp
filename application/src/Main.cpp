#include "ServerInstance.hpp"

int main() {
    // Singleton Application
    ServerInstance* serverInstance = ServerInstance::GetInstance();
    serverInstance -> Init();
    serverInstance -> Start();
}