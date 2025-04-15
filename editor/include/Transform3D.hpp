#ifndef TRANSFORM_HPP
#define TRANSFORM_HPP

#include "raymath.h"


class Transform3D {
    public:
    /* CONSTRUCTORS */
    Transform3D(const Vector3& pos, const Vector3& rot, const Vector3& scal) :  _position(pos), _rotation(rot), _scale(scal) {};
    Transform3D(const Vector3& pos, const Vector3& rot) : _position(pos), _rotation(rot), _scale(Vector3{1.0, 1.0, 1.0}) {};
    Transform3D(const Vector3& pos) : _position(pos), _rotation(Vector3{0.0, 0.0, 0.0}), _scale(Vector3{1.0, 1.0, 1.0}) {};
    Transform3D() : _position(Vector3{0.0, 0.0, 0.0}), _rotation(Vector3{0.0, 0.0, 0.0}), _scale(Vector3{1.0, 1.0, 1.0}) {};

    /* SETTERS */
    void SetPos(const Vector3& pos);
    void SetRot(const Vector3&  rot);
    void SetScale(const Vector3&  scal);

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
        Vector3 _position;
        // Rotation (pitch, roll , yaw)
        Vector3 _rotation;
        Vector3 _scale;
};

#endif