#ifndef TRANSFORM_HPP
#define TRANSFORM_HPP

#include "raymath.h"


struct Transform3D {

    public:
    /* CONSTRUCTORS */
    Transform3D(const Vector3& pos, const Vector3& rot, const Vector3& scal) :  _position(pos), _rotation(rot), _scale(scal) {};
    Transform3D(const Vector3& pos, const Vector3& rot) : _position(pos), _rotation(rot), _scale(Vector3{1.0, 1.0, 1.0}) {};
    Transform3D(const Vector3& pos) : _position(pos), _rotation(Vector3{0.0, 0.0, 0.0}), _scale(Vector3{1.0, 1.0, 1.0}) {};
    Transform3D() : _position(Vector3{0.0, 0.0, 0.0}), _rotation(Vector3{0.0, 0.0, 0.0}), _scale(Vector3{1.0, 1.0, 1.0}) {};

    /* GETTERS */
    Vector3& GetPos() const;
    Vector3& GetRot() const;
    Vector3& GetScale() const;

    /* SETTERS */
    void SetPos(const Vector3& pos);
    void SetRot(const Vector3&  rot);
    void SetScale(const Vector3&  scal);

    /* MODIFIER */

    private:
        Vector3 _position;
        Vector3 _rotation;
        Vector3 _scale;


};

#endif