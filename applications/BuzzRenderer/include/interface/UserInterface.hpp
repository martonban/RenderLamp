#ifndef USER_INTERFACE_HPP
#define USER_INTERFACE_HPP

#include <memory>

#include "interface/Printer.hpp"

class UserInterface {
    public:
        UserInterface();
        void Start();
    private:
        std::unique_ptr<Printer> mPrinter;
};


#endif