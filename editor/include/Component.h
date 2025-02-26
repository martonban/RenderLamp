#ifndef COMPONENT_H
#define COMPONENT_H

class Component {
    public:
        virtual void Update() = 0;
        virtual void Start() = 0;
        virtual void Destroy() = 0;
};

#endif