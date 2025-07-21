#ifndef COMPONENT_HPP
#define COMPONENT_HPP

#include <cstdint>

class Component {
    public:
        virtual ~Component() = default;
        virtual void Start() = 0;
        virtual void LogicUpdate() = 0;
        virtual void RenderUpdate();
        virtual void ImGUI();
        virtual void RayTracerSerializer();
        virtual void Destroy();
        uint64_t GetID() const { return id; }
    protected:
        uint64_t id;
};


#endif