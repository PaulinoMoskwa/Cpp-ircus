#include <gtest/gtest.h>
#include "CustomTest.h"
#include "../include/LengthLastWord.h"


TEST(TestLengthLastWord, LengthLastWord){

    Solution solution;

    GIVEN("a string")
    std::string s = "   fly me   to   the moon  ";

    WHEN("calling the function `lengthOfLastWord()`")
    int length_of_last_word = solution.lengthOfLastWord(s);

    THEN("the length of the last word is returned")
    ASSERT_EQ(length_of_last_word, 4);
}


// ---- Cooler version ----

// The param will be: tuple < string s, int expected_len >
class Test_LengthLastWord : public ::testing::TestWithParam<std::tuple<std::string, int>> {};

TEST_P(Test_LengthLastWord, LengthLastWord){

    Solution solution;

    GIVEN("a string")
    std::tuple<std::string, int> data = GetParam();
    std::string s = std::get<0>(data);

    WHEN("calling the function `lengthOfLastWord()`")
    int length_of_last_word = solution.lengthOfLastWord(s);

    THEN("the length of the last word is returned")
    ASSERT_EQ(length_of_last_word, std::get<1>(data));

}

INSTANTIATE_TEST_CASE_P(LengthLastWordInstance, Test_LengthLastWord, ::testing::Values(
    std::make_tuple("   fly me   to   the moon  ", 4),
    std::make_tuple("luffy is still joyboy", 6),
    std::make_tuple("Hello World", 5),
    std::make_tuple("a", 1)
));
