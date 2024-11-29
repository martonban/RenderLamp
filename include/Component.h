#ifndef COMPONENT_H
#define COMPONENT_H

class Component {
    public:
        virtual void Update() {};
        virtual void Start() {};
        virtual void Destroy() {};
};

#endif