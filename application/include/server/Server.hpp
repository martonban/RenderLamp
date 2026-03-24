#ifndef SERVER_HPP
#define SERVER_HPP

#include <memory>

#include "Arca.hpp"

#include "interfaces/IObserver.hpp"
#include "app/PrinterSystem.hpp"

class Server : public IObserver, public std::enable_shared_from_this<Server> {
    public:
        Server(std::weak_ptr<PrinterSystem> printer);
        void Start();
        void Subscribe();
        void Update(const ServerRequest& request) override;

    private:
        void AddNewProject(const std::filesystem::path& inputPath);
        void ListAllProjects();
        void StartRenderingPipeline(const std::filesystem::path& path);


        std::vector<std::pair<std::string, std::filesystem::path>> mProjects;
        std::shared_ptr<Arca::Module> mArcaModule;
        std::weak_ptr<PrinterSystem> mPrinterPtr;

        void StartSession();
};


#endif