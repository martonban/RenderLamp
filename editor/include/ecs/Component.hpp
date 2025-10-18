#ifndef COMPONENT_HPP
#define COMPONENT_HPP

#include <cstdint>

class Component {
    public:
        virtual ~Component() = default;
        virtual void Start() = 0;
        virtual void Tick() = 0;
        virtual void BuzzRendererConverter();
};

#endif