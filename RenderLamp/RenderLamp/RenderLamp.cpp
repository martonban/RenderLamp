#include <iostream>
#include "RenderLampManager.h"
#include "FileManager.h"

int main(){
    
    std::string testaData = "C:\\Art";

    FileManager fileManager;
    bool test = fileManager.IsThisPathExist(testaData);
    std::cout << test;

    //RenderLampManager manager;
    //manager.Init();
    //manager.Loop();
}
