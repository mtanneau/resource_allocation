#include "problem_data.hpp"
#include <gtest/gtest.h>
#include <string>

#ifndef TEST_DATA_DIR
#define TEST_DATA_DIR "./tests/data"
#endif

std::string get_test_data_dir() {
    const char* envVar = std::getenv("TEST_DATA_DIR");
    std::string tdd = envVar ? envVar : TEST_DATA_DIR;
    return tdd;
}

// Test parsing a valid file with integers
TEST(ProblemData, FileParser) {
    const std::string& test_data_dir = get_test_data_dir();
    std::string filepath =  test_data_dir + "/" + "test_data_1.txt";
    auto pbdata = problem_data();
    pbdata.parse_data(filepath);
    
    ASSERT_EQ(pbdata.num_items, 4);
    ASSERT_EQ(pbdata.resource_capacity, 100.01);
    ASSERT_EQ(pbdata.costs.size(), 4);
    ASSERT_EQ(pbdata.weights.size(), 4);
    EXPECT_EQ(pbdata.costs[0], 10.1);
    EXPECT_EQ(pbdata.costs[1], 10.2);
    EXPECT_EQ(pbdata.costs[2], 10.3);
    EXPECT_EQ(pbdata.costs[3], 10.4);
    EXPECT_EQ(pbdata.weights[0], 12.001);
    EXPECT_EQ(pbdata.weights[1], 34.002);
    EXPECT_EQ(pbdata.weights[2], 56.003);
    EXPECT_EQ(pbdata.weights[3], 78.004);
}

