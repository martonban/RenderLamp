#ifndef PRINTER_HPP
#define PRINTER_HPP

#include <array>
#include <sstream>
#include <string>
#include <iostream>

#ifdef _WIN32
#include <windows.h>
#endif

namespace Printer {

void PrintWelocome() {
#ifdef _WIN32
    static bool vtEnabled = false;
    if (!vtEnabled) {
        HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
        if (hOut != INVALID_HANDLE_VALUE) {
            DWORD mode = 0;
            if (GetConsoleMode(hOut, &mode)) {
                vtEnabled = SetConsoleMode(hOut, mode | ENABLE_VIRTUAL_TERMINAL_PROCESSING);
            }
        }
    }
#endif

static constexpr std::array<const char*, 6> palette{
    "\033[38;2; 30; 40; 60m",
    "\033[38;2; 45; 55; 75m",
    "\033[38;2; 70; 80;100m",
    "\033[38;2;100;110;130m",
    "\033[38;2;130;140;160m",
    "\033[38;2;160;170;190m"
};

    std::string art = R"(                                                                                          
    mmmmmm                              mm                         mm                        
    ##""""##                            ##                        ####                       
    ##    ##   m####m   ##m####m   m###m##   m####m    ##m####    ####     ##m####   m#####m 
    #######   ##mmmm##  ##"   ##  ##"  "##  ##mmmm##   ##"       ##  ##    ##"      ##"    " 
    ##  "##m  ##""""""  ##    ##  ##    ##  ##""""""   ##        ######    ##       ##       
    ##    ##  "##mmmm#  ##    ##  "##mm###  "##mmmm#   ##       m##  ##m   ##       "##mmmm# 
    ""    """   """""   ""    ""    """ ""    """""    ""       ""    ""   ""         """""  
                                                                                          
                                                                                         
       mmmm   mm         mmmmmm                                                              
     ##""""#  ##         ""##""                                                              
    ##"       ##           ##                                                                
    ##        ##           ##                                                                
    ##m       ##           ##                                                                
     ##mmmm#  ##mmmmmm   mm##mm                                                              
       """"   """"""""   """"""                                                              
    )";

    std::istringstream lines(art);
    std::string line;
    std::size_t idx = 0;

    while (std::getline(lines, line)) {
        std::cout << palette[idx % palette.size()] << line << "\033[0m\n";
        ++idx;
    }
}
}

#endif