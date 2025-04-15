#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include <iostream> 

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
};

#endif