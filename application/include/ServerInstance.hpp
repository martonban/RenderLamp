#ifndef SERVER_INSTANCE_HPP
#define SERVER_INSTANCE_HPP

#include "Arca.hpp"

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
        //std::uniqie<CliInterface> mCliInterface; 
};




#endif