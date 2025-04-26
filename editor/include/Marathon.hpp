#ifndef MARATHON_HPP
#define MARATHON_HPP

#include <string>
#include <memory>

#include "Arca.hpp"

class Marathon {
public:
    Marathon(const std::string& applicationName);
private:
    std::unique_ptr<Arca> arca;
};

#endif