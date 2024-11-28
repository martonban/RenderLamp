#ifndef COMPONENT_H
#define COMPONENT_H

/*
    virtual int must_haveto_implement() = 0;
    virtual int doesnt_have_to_impl();
*/

class Component {
    public:
        virtual void Update() {};
        virtual void Start() {};
        virtual void Destroy() {};
};

#endif