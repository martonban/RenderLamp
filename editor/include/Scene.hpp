#ifndef SCENE_HPP
#define SCENE_HPP

#include <vector>

#include "RendererRayLib.hpp"
#include "Entity.hpp"

class Scene {
    public:
        Scene(){
            
        };
        void Start();
        void Tick();
        void Destroy();
        void AddEntity(Entity entity);
    private:
        RendererRayLib renderer;
        std::vector<Entity> entity_vector;

};

#endif