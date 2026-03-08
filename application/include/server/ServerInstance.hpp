#ifndef SERVER_INSTANCE_HPP
#define SERVER_INSTANCE_HPP

#include <memory>

#include "Arca.hpp"

#include "app/CliInterface.hpp"

class ServerInstance {
    public: 
        ServerInstance(ServerInstance& instance) = delete;
        void operator= (const ServerInstance &) = delete;
        static ServerInstance* GetInstance();

        void Init();
        void Start();

    protected:
        ServerInstance();
        static ServerInstance* mServerInstance;
        std::unique_ptr<CliInterface> mCliInterface; 
};




#endif