#ifndef TRANSFORM_HPP
#define TRANSFORM_HPP

#include "raymath.h"
#include <nlohmann/json.hpp>


class Transform3D {
    public:
    /* CONSTRUCTORS */
    Transform3D(const nlohmann::json& jsonObject);
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
    void ChangeScale(const Vector3& scale);
    
    /* GETTERS */
    Vector3& GetPos() { return mPosition; }
    Vector3& GetRot() { return mRotation; }
    Vector3& GetScale()  {return mScale; }

    private:
        Vector3 mPosition;
        Vector3 mRotation;
        Vector3 mScale;
};

#endif