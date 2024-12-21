#ifndef SCENE_H
#define SCENE_H

#include <vector>

#include "RendererRayLib.h"
#include "Entity.h"


class Scene {
    public:
        Scene();
        void Start();
        void Tick();
        void Destroy();
        void AddEntity(Entity entity);
    private:
        RendererRayLib renderer;
        std::vector<Entity> entity_vector;
};

#endif