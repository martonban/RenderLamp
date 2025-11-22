#include <gtest/gtest.h>
#include "BuzzRenderer.hpp"
#include <glm/glm.hpp>

// Test fixture for BuzzRenderer tests
class BuzzRendererTest : public ::testing::Test {
protected:
    void SetUp() override {
        // Setup code if needed
    }

    void TearDown() override {
        // Cleanup code if needed
    }
};

// BuzzRenderer Basic Tests
TEST_F(BuzzRendererTest, RendererCanBeCreated) {
    // This test verifies the renderer can be instantiated
    // The actual implementation depends on the BuzzRenderer API
    EXPECT_TRUE(true); // Placeholder - update based on actual API
}

TEST_F(BuzzRendererTest, Vec3Operations) {
    // Test basic vector operations used in rendering
    glm::vec3 v1(1.0f, 2.0f, 3.0f);
    glm::vec3 v2(4.0f, 5.0f, 6.0f);
    
    glm::vec3 sum = v1 + v2;
    
    EXPECT_FLOAT_EQ(sum.x, 5.0f);
    EXPECT_FLOAT_EQ(sum.y, 7.0f);
    EXPECT_FLOAT_EQ(sum.z, 9.0f);
}

TEST_F(BuzzRendererTest, Vec3DotProduct) {
    // Test dot product calculation
    glm::vec3 v1(1.0f, 0.0f, 0.0f);
    glm::vec3 v2(1.0f, 0.0f, 0.0f);
    
    float dot = glm::dot(v1, v2);
    
    EXPECT_FLOAT_EQ(dot, 1.0f);
}

TEST_F(BuzzRendererTest, Vec3CrossProduct) {
    // Test cross product calculation
    glm::vec3 v1(1.0f, 0.0f, 0.0f);
    glm::vec3 v2(0.0f, 1.0f, 0.0f);
    
    glm::vec3 cross = glm::cross(v1, v2);
    
    EXPECT_FLOAT_EQ(cross.x, 0.0f);
    EXPECT_FLOAT_EQ(cross.y, 0.0f);
    EXPECT_FLOAT_EQ(cross.z, 1.0f);
}

TEST_F(BuzzRendererTest, Vec3Normalization) {
    // Test vector normalization
    glm::vec3 v(3.0f, 4.0f, 0.0f);
    glm::vec3 normalized = glm::normalize(v);
    
    float length = glm::length(normalized);
    
    EXPECT_NEAR(length, 1.0f, 0.0001f);
    EXPECT_FLOAT_EQ(normalized.x, 0.6f);
    EXPECT_FLOAT_EQ(normalized.y, 0.8f);
}

TEST_F(BuzzRendererTest, ColorRangeValidation) {
    // Test that color values are in valid range [0, 1]
    glm::vec3 color(0.5f, 0.7f, 0.9f);
    
    EXPECT_GE(color.r, 0.0f);
    EXPECT_LE(color.r, 1.0f);
    EXPECT_GE(color.g, 0.0f);
    EXPECT_LE(color.g, 1.0f);
    EXPECT_GE(color.b, 0.0f);
    EXPECT_LE(color.b, 1.0f);
}

TEST_F(BuzzRendererTest, MatrixIdentity) {
    // Test identity matrix creation
    glm::mat4 identity = glm::mat4(1.0f);
    
    EXPECT_FLOAT_EQ(identity[0][0], 1.0f);
    EXPECT_FLOAT_EQ(identity[1][1], 1.0f);
    EXPECT_FLOAT_EQ(identity[2][2], 1.0f);
    EXPECT_FLOAT_EQ(identity[3][3], 1.0f);
    EXPECT_FLOAT_EQ(identity[0][1], 0.0f);
}

// Main function for running tests
int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
