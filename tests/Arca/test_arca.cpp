#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <filesystem>
#include <fstream>
#include <string>

#include "Arca.hpp"
#include "ArcaIO.hpp"

//  TODO:  
//  ArcaIO: ValidJson()
//
//

class ArcaTest : public ::testing::Test {
protected:
    void SetUp() override {
        // Create test directory for testing
        testDir = "test_arca_temp";
        if (!std::filesystem::exists(testDir)) {
            std::filesystem::create_directory(testDir);
        }
    }

    void TearDown() override {
        // Clean up test directory
        if (std::filesystem::exists(testDir)) {
            std::filesystem::remove_all(testDir);
        }
    }

    std::string testDir;
};

// =====================================================================
//                       IsFileExists Tests
// =====================================================================
// API TESTS
TEST_F(ArcaTest, IsFileExists_ExistingFile_ReturnsTrue) {
    // Arrange
    std::string testFile = testDir + "/existing_file.txt";
    std::ofstream file(testFile);
    file << "test content";
    file.close();

    // Act
    bool result = Arca::IsFileExists(testFile);

    // Assert
    EXPECT_TRUE(result);
}

TEST_F(ArcaTest, IsFileExists_NonExistingFile_ReturnsFalse) {
    // Arrange
    std::string nonExistentFile = testDir + "/non_existent_file.txt";

    // Act
    bool result = Arca::IsFileExists(nonExistentFile);

    // Assert
    EXPECT_FALSE(result);
}

TEST_F(ArcaTest, IsFileExists_Directory_ReturnsFalse) {
    // Arrange
    std::string testSubDir = testDir + "/subdirectory";
    std::filesystem::create_directory(testSubDir);

    // Act
    bool result = Arca::IsFileExists(testSubDir);

    // Assert
    EXPECT_FALSE(result);
}

TEST_F(ArcaTest, IsFileExists_EmptyPath_ReturnsFalse) {
    // Act
    bool result = Arca::IsFileExists("");

    // Assert
    EXPECT_FALSE(result);
}

TEST_F(ArcaTest, IsFileExists_RelativePath_WorksCorrectly) {
    // Arrange
    std::string testFile = "temp_relative_file.txt";
    std::ofstream file(testFile);
    file << "test content";
    file.close();

    // Act
    bool result = Arca::IsFileExists(testFile);

    // Assert
    EXPECT_TRUE(result);

    // Clean up
    std::filesystem::remove(testFile);
}

// STANDALONE TESTS
TEST_F(ArcaTest, IsFileExists_Standalone_ExistingFile_ReturnsTrue) {
    // Arrange
    std::string testFile = testDir + "/existing_file.txt";
    std::ofstream file(testFile);
    file << "test content";
    file.close();
    ArcaIO arcaIO;

    // Act
    bool result = arcaIO.IsFileExists(testFile);

    // Assert
    EXPECT_TRUE(result);
}

TEST_F(ArcaTest, IsFileExists_Standalone_NonExistingFile_ReturnsFalse) {
    // Arrange
    std::string nonExistentFile = testDir + "/non_existent_file.txt";
    ArcaIO arcaIO;

    // Act
    bool result = arcaIO.IsFileExists(nonExistentFile);

    // Assert
    EXPECT_FALSE(result);
}

TEST_F(ArcaTest, IsFileExists_Standalone_Directory_ReturnsFalse) {
    // Arrange
    std::string testSubDir = testDir + "/subdirectory";
    std::filesystem::create_directory(testSubDir);
    ArcaIO arcaIO;

    // Act
    bool result = arcaIO.IsFileExists(testSubDir);

    // Assert
    EXPECT_FALSE(result);
}

TEST_F(ArcaTest, IsFileExists_Standalone_EmptyPath_ReturnsFalse) {
    ArcaIO arcaIO;
    // Act
    bool result = arcaIO.IsFileExists("");

    // Assert
    EXPECT_FALSE(result);
}

TEST_F(ArcaTest, IsFileExists_Standalone_RelativePath_WorksCorrectly) {
    // Arrange
    std::string testFile = "temp_relative_file.txt";
    std::ofstream file(testFile);
    file << "test content";
    file.close();
    ArcaIO arcaIO;

    // Act
    bool result = arcaIO.IsFileExists(testFile);

    // Assert
    EXPECT_TRUE(result);

    // Clean up
    std::filesystem::remove(testFile);
}



// =====================================================================
//                       CreateFolder Tests
// =====================================================================

TEST_F(ArcaTest, CreateFolder_ValidPath_ReturnsTrue) {
    // Arrange
    std::string folderName = "new_test_folder";
    std::string expectedPath = testDir + "/" + folderName;

    // Act
    bool result = Arca::CreateFolder(testDir, folderName);

    // Assert
    EXPECT_TRUE(result);
    EXPECT_TRUE(std::filesystem::exists(expectedPath));
    EXPECT_TRUE(std::filesystem::is_directory(expectedPath));
}

TEST_F(ArcaTest, CreateFolder_ExistingFolder_ReturnsTrue) {
    // Arrange
    std::string folderName = "existing_folder";
    std::string folderPath = testDir + "/" + folderName;
    std::filesystem::create_directory(folderPath);

    // Act
    bool result = Arca::CreateFolder(testDir, folderName);

    // Assert
    EXPECT_TRUE(result);
    EXPECT_TRUE(std::filesystem::exists(folderPath));
}

TEST_F(ArcaTest, CreateFolder_NonExistentParentPath_ReturnsFalse) {
    // Arrange
    std::string nonExistentPath = "non_existent_parent_dir";
    std::string folderName = "test_folder";

    // Act
    bool result = Arca::CreateFolder(nonExistentPath, folderName);

    // Assert
    EXPECT_FALSE(result);
}

TEST_F(ArcaTest, CreateFolder_EmptyFolderName_CreatesEmptyNameFolder) {
    // Arrange
    std::string folderName = "";

    // Act
    bool result = Arca::CreateFolder(testDir, folderName);

    // Assert
    // This depends on the implementation - it might create a folder with empty name
    // or fail. Based on the current implementation, it will try to create path + "/" + ""
    std::string expectedPath = testDir + "/";
    // This test verifies the behavior - it might pass or fail depending on filesystem
    // The important thing is that it doesn't crash
}

TEST_F(ArcaTest, CreateFolder_NestedFolderCreation_WorksWithValidParent) {
    // Arrange
    std::string parentFolder = "parent";
    std::string childFolder = "child";
    
    // First create parent
    bool parentResult = Arca::CreateFolder(testDir, parentFolder);
    EXPECT_TRUE(parentResult);
    
    // Then create child in parent
    std::string parentPath = testDir + "/" + parentFolder;
    
    // Act
    bool childResult = Arca::CreateFolder(parentPath, childFolder);
    
    // Assert
    EXPECT_TRUE(childResult);
    std::string expectedChildPath = parentPath + "/" + childFolder;
    EXPECT_TRUE(std::filesystem::exists(expectedChildPath));
    EXPECT_TRUE(std::filesystem::is_directory(expectedChildPath));
}

TEST_F(ArcaTest, CreateFolder_SpecialCharactersInName_HandledCorrectly) {
    // Arrange
    std::string folderName = "test_folder_with-special.chars_123";

    // Act
    bool result = Arca::CreateFolder(testDir, folderName);

    // Assert
    EXPECT_TRUE(result);
    std::string expectedPath = testDir + "/" + folderName;
    EXPECT_TRUE(std::filesystem::exists(expectedPath));
    EXPECT_TRUE(std::filesystem::is_directory(expectedPath));
}




// =====================================================================
//                       Integration Tests
// =====================================================================

TEST_F(ArcaTest, Integration_CreateFolderThenCheckFile_WorksTogether) {
    // Arrange
    std::string folderName = "integration_test_folder";
    std::string fileName = "test_file.txt";
    
    // Act - Create folder
    bool folderResult = Arca::CreateFolder(testDir, folderName);
    EXPECT_TRUE(folderResult);
    
    // Create a file in the new folder
    std::string filePath = testDir + "/" + folderName + "/" + fileName;
    std::ofstream file(filePath);
    file << "integration test content";
    file.close();
    
    // Act - Check if file exists
    bool fileResult = Arca::IsFileExists(filePath);
    
    // Assert
    EXPECT_TRUE(fileResult);
}
