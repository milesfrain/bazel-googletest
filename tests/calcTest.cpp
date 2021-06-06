#include "gtest/gtest.h"
#include "src/calc.h"

TEST(calcTest, addition)
{
    EXPECT_EQ(5, add(2,3));
}

TEST(calcTest, multiplication)
{
    EXPECT_FLOAT_EQ(6, multiply(2,3));
}
