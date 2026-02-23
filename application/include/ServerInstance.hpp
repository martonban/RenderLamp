#ifndef SERVER_INSTANCE_HPP
#define SERVER_INSTANCE_HPP

#include <memory>

#include "interface/UserInterface.hpp"

class ServerInstance {
    public:
        void Init();
        void Start();
        static ServerInstance& GetInstance() {
            static ServerInstance instance;
            return instance;
        }
    protected:
        ServerInstance() = default;
    private:
        std::unique_ptr<UserInterface> mUserInterface;
};

#endif