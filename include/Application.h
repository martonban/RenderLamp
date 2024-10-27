#ifndef APPLICATION_H
#define APPLICATION_H

#include <iostream> 

#include "raylib.h"


class Application {
    // Functions
    public:
        void Init();
        void Start();
        static Application& GetInstance() {
            static Application instance;
            return instance;
        }
    protected:
        Application() = default;
    private:

    // Data fileds Instances
    private:

};

#endif