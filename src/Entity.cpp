#include "Entity.h"

Entity::Entity():
    transform(
        Transform {
            Vector3 { 0, 0, 0 },
            Vector3 { 0, 0, 0 },
            Vector3 { 1, 1, 1 }
        }
    )
{}

Entity::Entity(Transform transform) : transform(transform) {}






Transform Entity::GetTransform() { return transform; }