#include "Transform.h"

// Constractors
Transform::Transform(Vector3 pos): pos(pos) {}

Transform::Transform(Vector3 pos, Vector3 rot) : pos(pos), rot(rot) {}

Transform::Transform(Vector3 pos, Vector3 rot, Vector3 scale) : pos(pos), rot(rot), scale(scale) {}


// Getters
Vector3 Transform::GetPos() { return pos; }

Vector3 Transform::GetRot() { return rot; }

Vector3 Transform::GetScale() { return scale; }


float Transform::GetPosX() { return pos.x; }

float Transform::GetPosY() { return pos.y; }

float Transform::GetPosZ() { return pos.z; }


float Transform::GetRotX() { return rot.x; }

float Transform::GetRotY() { return rot.y; }

float Transform::GetRotZ() { return rot.z; }


float Transform::GetScaleX() { return scale.x; }

float Transform::GetScaleY() { return scale.y; }

float Transform::GetScaleZ() { return scale.z; }