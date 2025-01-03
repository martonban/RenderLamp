#include <gtest/gtest.h>
#include "../include/Transform3D.h"

TEST(Transform3D, GetPos) {
    Transform3D transform = Transform3D({1, 2, 3});
    Vector3 pos = transform.GetPos();
    EXPECT_EQ(pos.x, 1);
    EXPECT_EQ(pos.y, 2);
    EXPECT_EQ(pos.z, 3);
}