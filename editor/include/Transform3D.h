#ifndef TRANSFORM_H
#define TRANSFORM_H

#include "raymath.h"


class Transform3D {
    private:
        Vector3 position;
        Vector3 rotation;
        Vector3 scale;

    public:
    // Constructors
    Transform3D(Vector3 pos, Vector3 rot, Vector3 scal) : position(pos), rotation(rot), scale(scal) {};
    Transform3D(Vector3 pos, Vector3 rot) : position(pos), rotation(rot), scale(Vector3{1.0, 1.0, 1.0}) {};
    Transform3D(Vector3 pos) : position(pos), rotation(Vector3{0.0, 0.0, 0.0}), scale(Vector3{1.0, 1.0, 1.0}) {};
    Transform3D() : position(Vector3{0.0, 0.0, 0.0}), rotation(Vector3{0.0, 0.0, 0.0}), scale(Vector3{1.0, 1.0, 1.0}) {};

    // Geters
    Vector3 GetPos() {};
    Vector3 GetRot() {};
    Vector3 GetScale() {};

    // Setters
    void SetPos(Vector3 pos) {};
    void SetRot(Vector3 rot) {};
    void SetScale(Vector3 scal) {};

    // Modifiers
    
};

#endif