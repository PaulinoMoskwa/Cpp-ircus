#include <gtest/gtest.h>
#include "../include/RemoveElement.h"
#include "CustomTest.h"


TEST(TestRemoveElement, RemoveElementFromVector) {

    Solution solution;

    GIVEN("a vector of integers and an integer value")
    std::vector<int> vector_1 = {3,2,2,3};
    int value_1 = 3;

    std::vector<int> vector_2 = {0,1,2,2,3,0,4,2};
    int value_2 = 2;

    WHEN("calling the function `removeElement()`")
    solution.removeElement(vector_1, value_1);
    solution.removeElement(vector_2, value_2);

    THEN("all the elements equal to the integer value are removed")
    std::vector<int> expected_vector_1 = {2,2};
    ASSERT_EQ(vector_1, expected_vector_1);

    std::vector<int> expected_vector_2 = {0,1,3,0,4};
    ASSERT_EQ(vector_2, expected_vector_2);

}


// ---- Cooler version ----

// The param will be: tuple < original_vector, value, expected_vector >
class Test_RemoveElement : public ::testing::TestWithParam<std::tuple<std::vector<int>, int, std::vector<int>>> {};

TEST_P(Test_RemoveElement, RemoveElementFromVector) {
    
    std::tuple<std::vector<int>, int, std::vector<int>> data = GetParam();

    Solution solution;

    GIVEN("a vector of integers and an integer value")
    std::vector<int> vector = std::get<0>(data);
    int value = std::get<1>(data);

    WHEN("calling the function `removeElement()`")
    solution.removeElement(vector, value);

    THEN("all the elements equal to the integer value are removed")
    std::vector<int> expected_vector = std::get<2>(data);
    ASSERT_EQ(vector, expected_vector);

}

INSTANTIATE_TEST_CASE_P(RemoveElementInstance, Test_RemoveElement, ::testing::Values(
    std::make_tuple(std::vector<int>{3,2,2,3}, 3, std::vector<int>{2,2}),
    std::make_tuple(std::vector<int>{0,1,2,2,3,0,4,2}, 2, std::vector<int>{0,1,3,0,4})
));