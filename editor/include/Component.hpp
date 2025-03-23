#ifndef COMPONENT_HPP
#define COMPONENT_HPP

class Component {
    public:
        virtual ~Component() = default;
        virtual void Update() = 0;
        virtual void Start() = 0;
        virtual void Destroy() = 0;
};

#endif