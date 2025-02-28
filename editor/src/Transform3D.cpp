#include "Transform3D.hpp"

Vector3 Transform3D::GetPos () {
    return position;
}

Vector3 Transform3D::GetRot () {
    return rotation;
}

Vector3 Transform3D::GetScale () {
    return scale;
}

void Transform3D::SetPos (Vector3 pos) { 
    position = pos; 
}

void Transform3D::SetRot (Vector3 rot) { 
    rotation = rot; 
}

void Transform3D::SetScale (Vector3 scal) { 
    scale = scal; 
}