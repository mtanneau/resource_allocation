#include "file_parser.h"
#include <gtest/gtest.h>
#include <fstream>
#include <vector>

// Helper function to create a temporary test file
void createTestFile(const std::string& filename, const std::string& content) {
    std::ofstream file(filename);
    file << content;
    file.close();
}

// Test parsing a valid file with integers
TEST(FileParserTest, ParseValidFile) {
    std::string testFile = "/tmp/test_valid.txt";
    createTestFile(testFile, "1\n2\n3\n4\n5\n");
    
    std::vector<int> numbers;
    bool result = parseIntegerFile(testFile, numbers);
    
    EXPECT_TRUE(result);
    ASSERT_EQ(numbers.size(), 5);
    EXPECT_EQ(numbers[0], 1);
    EXPECT_EQ(numbers[1], 2);
    EXPECT_EQ(numbers[2], 3);
    EXPECT_EQ(numbers[3], 4);
    EXPECT_EQ(numbers[4], 5);
}

// Test parsing a file with negative integers
TEST(FileParserTest, ParseNegativeIntegers) {
    std::string testFile = "/tmp/test_negative.txt";
    createTestFile(testFile, "-10\n-5\n0\n5\n10\n");
    
    std::vector<int> numbers;
    bool result = parseIntegerFile(testFile, numbers);
    
    EXPECT_TRUE(result);
    ASSERT_EQ(numbers.size(), 5);
    EXPECT_EQ(numbers[0], -10);
    EXPECT_EQ(numbers[1], -5);
    EXPECT_EQ(numbers[2], 0);
    EXPECT_EQ(numbers[3], 5);
    EXPECT_EQ(numbers[4], 10);
}

// Test parsing an empty file
TEST(FileParserTest, ParseEmptyFile) {
    std::string testFile = "/tmp/test_empty.txt";
    createTestFile(testFile, "");
    
    std::vector<int> numbers;
    bool result = parseIntegerFile(testFile, numbers);
    
    EXPECT_TRUE(result);
    EXPECT_EQ(numbers.size(), 0);
}

// Test parsing a file with empty lines
TEST(FileParserTest, ParseFileWithEmptyLines) {
    std::string testFile = "/tmp/test_empty_lines.txt";
    createTestFile(testFile, "1\n\n2\n\n\n3\n");
    
    std::vector<int> numbers;
    bool result = parseIntegerFile(testFile, numbers);
    
    EXPECT_TRUE(result);
    ASSERT_EQ(numbers.size(), 3);
    EXPECT_EQ(numbers[0], 1);
    EXPECT_EQ(numbers[1], 2);
    EXPECT_EQ(numbers[2], 3);
}

// Test parsing a non-existent file
TEST(FileParserTest, ParseNonExistentFile) {
    std::string testFile = "/tmp/nonexistent_file_12345.txt";
    
    std::vector<int> numbers;
    bool result = parseIntegerFile(testFile, numbers);
    
    EXPECT_FALSE(result);
}

// Test parsing a file with invalid content
TEST(FileParserTest, ParseInvalidContent) {
    std::string testFile = "/tmp/test_invalid.txt";
    createTestFile(testFile, "1\n2\nabc\n4\n");
    
    std::vector<int> numbers;
    bool result = parseIntegerFile(testFile, numbers);
    
    EXPECT_FALSE(result);
}

// Test parsing a file with large integers
TEST(FileParserTest, ParseLargeIntegers) {
    std::string testFile = "/tmp/test_large.txt";
    createTestFile(testFile, "2147483647\n-2147483648\n");
    
    std::vector<int> numbers;
    bool result = parseIntegerFile(testFile, numbers);
    
    EXPECT_TRUE(result);
    ASSERT_EQ(numbers.size(), 2);
    EXPECT_EQ(numbers[0], 2147483647);
    EXPECT_EQ(numbers[1], -2147483648);
}
