#include "Transform3D.h"

// Getters
Vector3 Transform3D::GetPos() { return transform.pos; }

Vector3 Transform3D::GetRot() { return transform.rot; }

Vector3 Transform3D::GetScale() { return transform.scale; }


float Transform3D::GetPosX() { return transform.pos.x; }

float Transform3D::GetPosY() { return transform.pos.y; }

float Transform3D::GetPosZ() { return transform.pos.z; }


float Transform3D::GetRotX() { return transform.rot.x; }

float Transform3D::GetRotY() { return transform.rot.y; }

float Transform3D::GetRotZ() { return transform.rot.z; }


float Transform3D::GetScaleX() { return transform.scale.x; }

float Transform3D::GetScaleY() { return transform.scale.y; }

float Transform3D::GetScaleZ() { return transform.scale.z; }