#ifndef RENDERING_SERVER_HPP
#define RENDERING_SERVER_HPP

#include <memory>

#include "interface/Printer.hpp"

class RenderingServer {
    public:
        void Init();
        void Start();
        static RenderingServer& GetInstance() {
            static RenderingServer instance;
            return instance;
        }
    protected:
        RenderingServer() = default;
    private:
        std::unique_ptr<Printer> mPrinter;
        
};

#endif