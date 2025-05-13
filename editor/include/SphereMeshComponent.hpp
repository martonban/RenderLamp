#ifndef SPHERE_MESH_COMPONENT_HPP
#define SPHERE_MESH_COMPONENT_HPP

#include "raylib.h"
#include "raymath.h"

#include "Component.hpp"



class SphereMeshComponent : public Component {
public:
    SphereMeshComponent(Vector3 pos, float r);
    void Update();
private: 
    Vector3 mPos;
    float mRadius;
};
 
#endif