#ifndef TRANSFORM_H
#define TRANSFORM_H

#include "raymath.h"

#include "Component.h"

class Transform : Component {
    public:
        // Constractors
        Transform(Vector3 _pos);
        Transform(Vector3 pos, Vector3 rot);
        Transform(Vector3 pos, Vector3 rot, Vector3 scale);
        // Position Realted Methods

        // Rotation Related Methods

        // Scale Related Methods

        // Transformation Methods

    private:
        Vector3 pos {0};
        Vector3 rot {0};
        Vector3 scale {0};
};


#endif