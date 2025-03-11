#include "Transform3D.hpp"

void Transform3D::SetPos(const Vector3& pos) {
    _position = pos;
}

void Transform3D::SetRot(const Vector3& rot) {
    _rotation = rot;
}

void Transform3D::SetScale(const Vector3& scal) {
    _scale = scal;
}

void Transform3D::ChangeWorldPosition(const Vector3& translation) {
    _position = Vector3Add(_position, translation);
}

void Transform3D::ChangeRotation(const Vector3& rotation) {
    _rotation = Vector3Add(_rotation, rotation);
}

void Transform3D::ChangeScale(const Vector3& scale) {
    _scale = Vector3Multiply(_scale, scale);
}


Vector3 Transform3D::GetPos() {
    return _position;
}

Vector3 Transform3D::GetRot() {
    return _rotation;
}

Vector3 Transform3D::GetScale() {
    return _scale;
}