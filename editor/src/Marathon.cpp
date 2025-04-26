#include "Marathon.hpp"

Marathon::Marathon(const std::string& applicationName) {
    arca = std::make_unique<Arca>(applicationName);
}