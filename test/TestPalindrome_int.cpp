#include <gtest/gtest.h>
#include "../include/Palindrome_int.h"


TEST(TestPalindrome, Palindrome) {
    int x = 121;
    int y = -121;
    int z = 10;

    Solution solution;

    ASSERT_TRUE(solution.isPalindrome(x));
    ASSERT_FALSE(solution.isPalindrome(y));
    ASSERT_FALSE(solution.isPalindrome(z));
}


// ---- Cooler version ----

class Test_Palindrome : public ::testing::TestWithParam<int> {};
class Test_NonPalindrome : public ::testing::TestWithParam<int> {};

TEST_P(Test_Palindrome, Palindrome) {
    int x = GetParam();
    Solution solution;
    ASSERT_TRUE(solution.isPalindrome(x)) << 
        "The value " << x << " should be palindrome." << std::endl;
}

TEST_P(Test_NonPalindrome, NonPalindrome) {
    int x = GetParam();
    Solution solution;
    ASSERT_FALSE(solution.isPalindrome(x)) << 
        "The value " << x << " should not be palindrome." << std::endl;
}

INSTANTIATE_TEST_SUITE_P(PalindromeTestInstance, Test_Palindrome, ::testing::Values(
    121,
    1221,
    12321,
    1001
));

INSTANTIATE_TEST_SUITE_P(NonPalindromeTestInstance, Test_NonPalindrome, ::testing::Values(
    -121,
    10,
    1241,
    10021
));
