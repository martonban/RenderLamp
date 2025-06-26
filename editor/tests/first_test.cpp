#include <gtest/gtest.h>
#include "Transform3D.hpp"

// Demonstrate some basic assertions.
TEST(HelloTest, BasicAssertions) {
  // Expect two strings not to be equal.
  EXPECT_STRNE("hello", "world");
  // Expect equality.
  EXPECT_EQ(7 * 6, 44);
}



TEST(Transform3DTest, DefaultConstructor) {
  Transform3D transform;

  // Expect default position to be (0, 0, 0)
  Vector3 position = transform.GetPos();
  EXPECT_EQ(position.x, 0.0f);
  EXPECT_EQ(position.y, 0.0f);
  EXPECT_EQ(position.z, 0.0f);

  // Expect default rotation to be (0, 0, 0)
  Vector3 rotation = transform.GetRot();
  EXPECT_EQ(rotation.x, 0.0f);
  EXPECT_EQ(rotation.y, 0.0f);
  EXPECT_EQ(rotation.z, 0.0f);

  // Expect default scale to be (1, 1, 1)
  Vector3 scale = transform.GetScale();
  EXPECT_EQ(scale.x, 2.0f);
  EXPECT_EQ(scale.y, 1.0f);
  EXPECT_EQ(scale.z, 1.0f);
}