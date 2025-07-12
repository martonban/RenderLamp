#ifndef TRANSFORM_HPP
#define TRANSFORM_HPP

#include "raymath.h"


class Transform3D {
    public:
    /* CONSTRUCTORS */
    Transform3D(const Vector3& pos, const Vector3& rot, const Vector3& scal) :  mPosition(pos), mRotation(rot), mScale(scal) {};
    Transform3D(const Vector3& pos, const Vector3& rot) : mPosition(pos), mRotation(rot), mScale(Vector3{1.0, 1.0, 1.0}) {};
    Transform3D(const Vector3& pos) : mPosition(pos), mRotation(Vector3{0.0, 0.0, 0.0}), mScale(Vector3{1.0, 1.0, 1.0}) {};
    Transform3D() : mPosition(Vector3{0.0, 0.0, 0.0}), mRotation(Vector3{0.0, 0.0, 0.0}), mScale(Vector3{1.0, 1.0, 1.0}) {};

    /* SETTERS */
    void SetPos(const Vector3& pos);
    void SetRot(const Vector3&  rot);
    void SetScale(const Vector3& scal);

    /* MODIFIERS */
    void ChangeWorldPosition(const Vector3& translation);
    void ChangeRotation(const Vector3& rotation);
    // The given vector need to be a multiplier
    void ChangeScale(const Vector3& scale);
    
    /* GETTERS */
    // Simple getters
    Vector3 GetPos();
    Vector3 GetRot();
    Vector3 GetScale();
    // Matrix Transformation getters
    Matrix GetWorldSpaceMatrix() const;


    /* SERIALIZER */

    private:
        // World Positions
        Vector3 mPosition;
        // Rotation (pitch, roll , yaw)
        Vector3 mRotation;
        Vector3 mScale;
};

#endif