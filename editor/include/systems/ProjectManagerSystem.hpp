#ifndef PROJECT_MANAGER_SYSTEM_HPP
#define PROJECT_MANAGER_SYSTEM_HPP

#include "Arca.hpp"

class ProjectManagerSystem {
    public: 
        static ProjectManagerSystem& GetInstance() {
            static ProjectManagerSystem instance;
            return instance;
        }
        void StartSystem();

        
    protected:
        ProjectManagerSystem() = default;
    private:
        std::shared_ptr<ArcaContainer> projectList;
        ProjectManagerSystem(const ProjectManagerSystem&) = delete;
        ProjectManagerSystem& operator=(const ProjectManagerSystem&) = delete;
};

#endif