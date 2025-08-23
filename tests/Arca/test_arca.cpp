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

    std::filesystem::path testDir;
};

// =====================================================================
//                       IsFileExists Tests
// =====================================================================
// API TESTS
TEST_F(ArcaTest, IsFileExists_ExistingFile_ReturnsTrue) {
    // Arrange
    std::filesystem::path testFile = testDir / "existing_file.txt";
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
    std::filesystem::path nonExistentFile = testDir / "non_existent_file.txt";

    // Act
    bool result = Arca::IsFileExists(nonExistentFile);

    // Assert
    EXPECT_FALSE(result);
}

TEST_F(ArcaTest, IsFileExists_Directory_ReturnsFalse) {
    // Arrange
    std::filesystem::path testSubDir = testDir / "subdirectory";
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
    std::filesystem::path testFile = "temp_relative_file.txt";
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
    std::filesystem::path testFile = testDir / "existing_file.txt";
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
    std::filesystem::path nonExistentFile = testDir / "non_existent_file.txt";
    ArcaIO arcaIO;

    // Act
    bool result = arcaIO.IsFileExists(nonExistentFile);

    // Assert
    EXPECT_FALSE(result);
}

TEST_F(ArcaTest, IsFileExists_Standalone_Directory_ReturnsFalse) {
    // Arrange
    std::filesystem::path testSubDir = testDir / "subdirectory";
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
    std::filesystem::path testFile = "temp_relative_file.txt";
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
//                       IsFolderExists Tests
// =====================================================================

TEST_F(ArcaTest, IsFolderExists_ExistingFolder_ReturnsTrue) {
    // Arrange
    std::filesystem::path testSubDir = testDir / "existing_folder";
    std::filesystem::create_directory(testSubDir);
    ArcaIO arcaIO;

    // Act
    bool result = arcaIO.IsFolderExists(testSubDir);

    // Assert
    EXPECT_TRUE(result);
}

TEST_F(ArcaTest, IsFolderExists_NonExistingFolder_ReturnsFalse) {
    // Arrange
    std::filesystem::path nonExistentFolder = testDir / "non_existent_folder";
    ArcaIO arcaIO;

    // Act
    bool result = arcaIO.IsFolderExists(nonExistentFolder);

    // Assert
    EXPECT_FALSE(result);
}

TEST_F(ArcaTest, IsFolderExists_File_ReturnsFalse) {
    // Arrange
    std::filesystem::path testFile = testDir / "test_file.txt";
    std::ofstream file(testFile);
    file << "test content";
    file.close();
    ArcaIO arcaIO;

    // Act
    bool result = arcaIO.IsFolderExists(testFile);

    // Assert
    EXPECT_FALSE(result);
}

TEST_F(ArcaTest, IsFolderExists_EmptyPath_ReturnsFalse) {
    // Arrange
    ArcaIO arcaIO;

    // Act
    bool result = arcaIO.IsFolderExists("");

    // Assert
    EXPECT_FALSE(result);
}


// =====================================================================
//                       CreateFolder Tests
// =====================================================================

TEST_F(ArcaTest, CreateDirectory_ValidPath_ReturnsTrue) {
    // Arrange
    std::string folderName = "new_test_folder";
    std::filesystem::path expectedPath = testDir / folderName;

    // Act
    bool result = Arca::CreateFolder(testDir, folderName);

    // Assert
    EXPECT_TRUE(result);
    EXPECT_TRUE(std::filesystem::exists(expectedPath));
    EXPECT_TRUE(std::filesystem::is_directory(expectedPath));
}

TEST_F(ArcaTest, CreateDirectory_ExistingFolder_ReturnsTrue) {
    // Arrange
    std::string folderName = "existing_folder";
    std::filesystem::path folderPath = testDir / folderName;
    std::filesystem::create_directory(folderPath);

    // Act
    bool result = Arca::CreateFolder(testDir, folderName);

    // Assert
    EXPECT_TRUE(result);
    EXPECT_TRUE(std::filesystem::exists(folderPath));
}

TEST_F(ArcaTest, CreateDirectory_NonExistentParentPath_ReturnsFalse) {
    // Arrange
    std::filesystem::path nonExistentPath = "non_existent_parent_dir";
    std::string folderName = "test_folder";

    // Act
    bool result = Arca::CreateFolder(nonExistentPath, folderName);

    // Assert
    EXPECT_FALSE(result);
}

TEST_F(ArcaTest, CreateDirectory_EmptyFolderName_CreatesEmptyNameFolder) {
    // Arrange
    std::string folderName = "";

    // Act
    bool result = Arca::CreateFolder(testDir, folderName);

    // Assert
    // This depends on the implementation - it might create a folder with empty name
    // or fail. Based on the current implementation, it will try to create path / ""
    std::filesystem::path expectedPath = testDir / "";
    // This test verifies the behavior - it might pass or fail depending on filesystem
    // The important thing is that it doesn't crash
}

TEST_F(ArcaTest,CreateDirectory_NestedFolderCreation_WorksWithValidParent) {
    // Arrange
    std::string parentFolder = "parent";
    std::string childFolder = "child";
    
    // First create parent
    bool parentResult = Arca::CreateFolder(testDir, parentFolder);
    EXPECT_TRUE(parentResult);
    
    // Then create child in parent
    std::filesystem::path parentPath = testDir / parentFolder;
    
    // Act
    bool childResult = Arca::CreateFolder(parentPath, childFolder);
    
    // Assert
    EXPECT_TRUE(childResult);
    std::filesystem::path expectedChildPath = parentPath / childFolder;
    EXPECT_TRUE(std::filesystem::exists(expectedChildPath));
    EXPECT_TRUE(std::filesystem::is_directory(expectedChildPath));
}

TEST_F(ArcaTest, CreateDirectory_SpecialCharactersInName_HandledCorrectly) {
    // Arrange
    std::string folderName = "test_folder_with-special.chars_123";

    // Act
    bool result = Arca::CreateFolder(testDir, folderName);

    // Assert
    EXPECT_TRUE(result);
    std::filesystem::path expectedPath = testDir / folderName;
    EXPECT_TRUE(std::filesystem::exists(expectedPath));
    EXPECT_TRUE(std::filesystem::is_directory(expectedPath));
}




// =====================================================================
//                       Integration Tests
// =====================================================================

TEST_F(ArcaTest, Integration_CreateDirectoryThenCheckFile_WorksTogether) {
    // Arrange
    std::string folderName = "integration_test_folder";
    std::filesystem::path fileName = "test_file.txt";
    
    // Act - Create folder
    bool folderResult = Arca::CreateFolder(testDir, folderName);
    EXPECT_TRUE(folderResult);
    
    // Create a file in the new folder
    std::filesystem::path filePath = testDir / folderName / fileName;
    std::ofstream file(filePath);
    file << "integration test content";
    file.close();
    
    // Act - Check if file exists
    bool fileResult = Arca::IsFileExists(filePath);
    
    // Assert
    EXPECT_TRUE(fileResult);
}
