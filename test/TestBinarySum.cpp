#include <gtest/gtest.h>
#include "CustomTest.h"
#include "../include/BinarySum.h"


TEST(TestBinarySum, BinarySum) {

    Solution solution;

    GIVEN("two binary numbers as strings")
    std::string x = "11";
    std::string y = "1";

    WHEN("calling the function `addBinary()`")
    std::string result = solution.addBinary(x, y);

    THEN("the function returns the binary sum of the two numbers")
    ASSERT_EQ(result, "100");
}


// ---- Cooler version ----

// The param will be: vector < string a, string b, string expected result >
class Test_BinarySum : public ::testing::TestWithParam<std::vector<std::string>> {};

TEST_P(Test_BinarySum, BinarySum) {

    Solution solution;

    GIVEN("two binary numbers as strings")
    std::vector<std::string> data = GetParam();
    std::string x = data[0];
    std::string y = data[1];

    WHEN("calling the function `addBinary()`")
    std::string result = solution.addBinary(x, y);

    THEN("the function returns the binary sum of the two numbers")
    ASSERT_EQ(result, data[2]);
}

INSTANTIATE_TEST_CASE_P(BinarySumInstance, Test_BinarySum, ::testing::Values(
    std::vector<std::string> {"11", "1", "100"},
    std::vector<std::string> {"1010", "1011", "10101"},
    std::vector<std::string> {"111", "1", "1000"}
));
