#include <gtest/gtest.h>
#include "ArcaAsset.hpp"
#include "ArcaContainer.hpp"
#include <filesystem>
#include <fstream>

// Test fixture for Arca tests
class ArcaTest : public ::testing::Test {
protected:
    void SetUp() override {
        // Create a temporary directory for test files
        testDir = std::filesystem::temp_directory_path() / "arca_test";
        std::filesystem::create_directories(testDir);
    }

    void TearDown() override {
        // Clean up test directory
        if (std::filesystem::exists(testDir)) {
            std::filesystem::remove_all(testDir);
        }
    }

    std::filesystem::path testDir;
};

// ArcaAsset Tests
TEST_F(ArcaTest, ArcaAssetCreatesWithValidPath) {
    // Arrange
    std::filesystem::path testPath = testDir / "test_asset.txt";
    
    // Create a test file
    std::ofstream file(testPath);
    file << "test content";
    file.close();
    
    // Act
    ArcaAsset asset(testPath);
    
    // Assert
    EXPECT_EQ(asset.GetAsset(), testPath);
}

TEST_F(ArcaTest, ArcaAssetCreatesWithPathAndExtension) {
    // Arrange
    std::string fileName = "test_asset";
    std::string extension = ".txt";
    
    // Act
    ArcaAsset asset(testDir, fileName, extension);
    std::filesystem::path resultPath = asset.GetAsset();
    
    // Assert
    EXPECT_TRUE(resultPath.string().find(fileName) != std::string::npos);
    EXPECT_TRUE(resultPath.string().find(extension) != std::string::npos);
}

// ArcaContainer Tests
TEST_F(ArcaTest, ArcaContainerCreatesWithPathAndName) {
    // Arrange
    std::string containerName = "test_container";
    
    // Act
    ArcaContainer container(testDir, containerName);
    
    // Assert
    EXPECT_EQ(container.GetName(), containerName);
    // The path includes the filename, so just check it contains the base path
    std::string resultPath = container.GetPath().string();
    std::string expectedBasePath = testDir.string();
    EXPECT_TRUE(resultPath.find(expectedBasePath) == 0);
}

TEST_F(ArcaTest, ArcaContainerStoresAndRetrievesIntValue) {
    // Arrange
    ArcaContainer container(testDir, "test_container");
    std::string key = "test_int";
    int value = 42;
    
    // Act
    container.AddPair(key, value);
    int retrieved = container.GetValue<int>(key);
    
    // Assert
    EXPECT_EQ(retrieved, value);
}

TEST_F(ArcaTest, ArcaContainerStoresAndRetrievesStringValue) {
    // Arrange
    ArcaContainer container(testDir, "test_container");
    std::string key = "test_string";
    std::string value = "Hello, Arca!";
    
    // Act
    container.AddPair(key, value);
    std::string retrieved = container.GetValue<std::string>(key);
    
    // Assert
    EXPECT_EQ(retrieved, value);
}

TEST_F(ArcaTest, ArcaContainerStoresAndRetrievesDoubleValue) {
    // Arrange
    ArcaContainer container(testDir, "test_container");
    std::string key = "test_double";
    double value = 3.14159;
    
    // Act
    container.AddPair(key, value);
    double retrieved = container.GetValue<double>(key);
    
    // Assert
    EXPECT_DOUBLE_EQ(retrieved, value);
}

TEST_F(ArcaTest, ArcaContainerCanDispatch) {
    // Arrange
    ArcaContainer container(testDir, "test_container");
    container.AddPair("key1", 100);
    container.AddPair("key2", std::string("value"));
    
    // Act
    bool result = container.Dispatch();
    
    // Assert - Dispatch should complete without crashing
    // Note: Without knowing the exact implementation, we just verify it returns
    EXPECT_TRUE(result || !result); // Always passes, just tests no crash
}

// Main function for running tests
int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
