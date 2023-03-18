#include <gtest/gtest.h>
#include "../include/Example.h"

/***
    Format of the Google Tests for C++:
        TEST(suite_test_name, test_name)
***/

TEST(ExampleTest_1, DemonstrateGTestMacros) {
    EXPECT_TRUE(true);
    ASSERT_TRUE(true);
}

TEST(ExampleTest_2, DemonstrateGTestMacros) {
    EXPECT_EQ(true, true);
}


/* The following is a failing test (purposely)

bool f(){
    return true;
}

TEST(ExampleTest_3, DemonstrateGTestMacros) {
    const bool result = f();
    ASSERT_EQ(result, true);
    // We can add a message that appears in case of failures
    //ASSERT_EQ(result, false) << "Halo, it's true!!" ;

    // The message can be convenient if for example we have:
    const int integer = 4;
    for(int i = 4; i < 6; ++i) {
        ASSERT_EQ(i, integer) << "The probelm is that we have i = " << i << " and integer = " << integer;
    }
}
*/

TEST(ExampleTest_4, MultiplyAndCumuluate) {
    int x = 42;
    int y = 16;
    int sum = 100;
    int old_sum = sum;
    int expected_new_sum = old_sum + x * y;
    EXPECT_EQ(MAC(x, y, sum), expected_new_sum);
    EXPECT_EQ(sum, expected_new_sum);

}

TEST(ExampleTest_5, Square) {
    int x = 5;
    int expected_square = 25;
    EXPECT_EQ(
        Square(x),
        expected_square
    );
}

/***
    What if there is some common structrue for the tests?
    To avoid code duplication we can create a fixture using a struct.
    This struct will inherit from a special class testing::Test
***/

struct ExampleTests_Fixture : public ::testing::Test {
    
    int* x;
    
    int get_x(){
        return *x;
    }

    virtual void SetUp() override {
        x = new int(42); 
    }

    virtual void TearDown() override {
        delete x;
    }
};

/***
    Now that there is this struct `TEST` becomes `TEST_F`, and the testuite name
    has to be `ExampleTests_Fixture`
***/

TEST_F(ExampleTests_Fixture, MultiplyAndCumuluate) {
    int y = 16;
    int sum = 100;
    int old_sum = sum;
    int expected_new_sum = old_sum + get_x() * y;
    EXPECT_EQ(MAC(get_x(), y, sum), expected_new_sum);
    EXPECT_EQ(sum, expected_new_sum);
}

TEST_F(ExampleTests_Fixture, Square) {
    int expected_square = get_x() * get_x();
    EXPECT_EQ(Square(get_x()), expected_square);
}

/***
    In VSCode it is possible to run the tests directly directly through the button (Run CTest).
    To do this, it is necessary to also select a `Kit` (down).

    Otherwise, it is possible to run the tests from terminal:
        .\build\test\ExampleTests.exe

    Some cool filters:
        .\build\test\ExampleTests.exe --gtest_filter=ExampleTest_1*
        .\build\test\ExampleTests.exe --gtest_filter=*Square
***/