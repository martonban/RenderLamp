#ifndef SERVER_HPP
#define SERVER_HPP

#include <memory>

#include "interfaces/IObserver.hpp"
#include "app/PrinterSystem.hpp"

class Server : public IObserver, public std::enable_shared_from_this<Server> {
    public:
        Server(std::weak_ptr<PrinterSystem> printer);
        void Subscribe();
        void Update(const ServerRequest& request) override;
        void StartSession();
    private:
        std::weak_ptr<PrinterSystem> mPrinterPtr;
};


#endif