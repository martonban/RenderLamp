#ifndef APPLICATION_H
#define APPLICATION_H

#include "raylib.h"



class Application {
    public:
        void Init();
        void Start();

        static Application& GetInstance() {
            static Application instance;
            return instance;
        }
    protected:
        Application() = default;
};

#endif