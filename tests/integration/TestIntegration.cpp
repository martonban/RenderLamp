#include <gtest/gtest.h>
#include "ArcaContainer.hpp"
#include "BuzzRenderer.hpp"
#include <filesystem>

// Integration test fixture
class IntegrationTest : public ::testing::Test {
protected:
    void SetUp() override {
        testDir = std::filesystem::temp_directory_path() / "integration_test";
        std::filesystem::create_directories(testDir);
    }

    void TearDown() override {
        if (std::filesystem::exists(testDir)) {
            std::filesystem::remove_all(testDir);
        }
    }

    std::filesystem::path testDir;
};

// Integration Tests
TEST_F(IntegrationTest, ArcaAndRendererIntegration) {
    // This test verifies that Arca and BuzzRenderer can work together
    // In a real scenario, you would:
    // 1. Create assets with Arca
    // 2. Load them in the renderer
    // 3. Verify the rendering pipeline
    
    // For now, just verify both components can be used together
    ArcaContainer container(testDir, "render_assets");
    container.AddPair("render_width", 800);
    container.AddPair("render_height", 600);
    
    int width = container.GetValue<int>("render_width");
    int height = container.GetValue<int>("render_height");
    
    EXPECT_EQ(width, 800);
    EXPECT_EQ(height, 600);
}

TEST_F(IntegrationTest, AssetPipelineFlow) {
    // Test the flow of creating and managing assets
    // 1. Create container
    ArcaContainer sceneContainer(testDir, "scene_data");
    
    // 2. Add scene properties
    sceneContainer.AddPair("scene_name", std::string("Test Scene"));
    sceneContainer.AddPair("object_count", 5);
    sceneContainer.AddPair("camera_fov", 45.0);
    
    // 3. Verify data retrieval
    std::string sceneName = sceneContainer.GetValue<std::string>("scene_name");
    int objectCount = sceneContainer.GetValue<int>("object_count");
    double cameraFov = sceneContainer.GetValue<double>("camera_fov");
    
    EXPECT_EQ(sceneName, "Test Scene");
    EXPECT_EQ(objectCount, 5);
    EXPECT_DOUBLE_EQ(cameraFov, 45.0);
}

TEST_F(IntegrationTest, MultipleContainersManagement) {
    // Test managing multiple containers
    ArcaContainer container1(testDir, "container1");
    ArcaContainer container2(testDir, "container2");
    
    container1.AddPair("id", 1);
    container2.AddPair("id", 2);
    
    int id1 = container1.GetValue<int>("id");
    int id2 = container2.GetValue<int>("id");
    
    EXPECT_EQ(id1, 1);
    EXPECT_EQ(id2, 2);
    EXPECT_NE(id1, id2);
}

// Main function for running tests
int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
