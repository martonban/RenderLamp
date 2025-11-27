
#include "interface/Printer.hpp"

int main() {
    Printer printer = Printer{};
    printer.PrintWelcome();
    char c;
    std::cin >> c;
    return 0;
}