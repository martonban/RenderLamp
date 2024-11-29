#ifndef TRANSFORM_H
#define TRANSFORM_H

#include "raymath.h"

#include "Component.h"

class Transform : Component {
    public:
        // Constractors
        Transform(Vector3 pos);
        Transform(Vector3 pos, Vector3 rot);
        Transform(Vector3 pos, Vector3 rot, Vector3 scale);
 


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
        Vector3 pos {0};
        Vector3 rot {0};
        Vector3 scale {1};
};


#endif