#include "Transform.h"

Transform::Transform(Vector3 _pos): pos(_pos) {}

Transform::Transform(Vector3 _pos, Vector3 _rot) : pos(_pos), rot(_rot) {}

Transform::Transform(Vector3 _pos, Vector3 _rot, Vector3 _scale) : pos(_pos), rot(_rot), scale(_scale) {}

