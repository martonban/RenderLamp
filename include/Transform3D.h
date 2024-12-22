#ifndef TRANSFORM_H
#define TRANSFORM_H

#include "raymath.h"

struct TransformData {
    Vector3 pos;
    Vector3 rot;
    Vector3 scale;
};

class Transform3D {
    public:
        // Constructors
        Transform3D(Vector3 pos) {
            transform.pos = pos;
            transform.rot = {0};
            transform.scale = {0};
        }
        Transform3D(Vector3 pos, Vector3 rot) {
            transform.pos = pos;
            transform.rot = rot;
            transform.scale = {0};
        }

        Transform3D(Vector3 pos, Vector3 rot, Vector3 scale) {
            transform.pos = pos;
            transform.rot = rot;
            transform.scale = scale;
        }
        // Getters
        Vector3 GetPos();
        Vector3 GetRot();
        Vector3 GetScale();
        
        float GetPosX();
        float GetPosY();
        float GetPosZ();

        float GetRotX();
        float GetRotY();
        float GetRotZ();

        float GetScaleX();
        float GetScaleY();
        float GetScaleZ();

    private:
        struct TransformData transform;
};

#endif