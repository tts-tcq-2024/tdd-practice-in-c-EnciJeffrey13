#include <gtest/gtest.h>
#include "StringCalculator.h"

TEST(StringCalculatorTest, ReturnsZeroForEmptyString) {
    StringCalculator calculator;
    EXPECT_EQ(calculator.Add(""), 0);
}

TEST(StringCalculatorTest, ReturnsSumForSingleNumber) {
    StringCalculator calculator;
    EXPECT_EQ(calculator.Add("1"), 1);
}

TEST(StringCalculatorTest, ReturnsSumForTwoNumbers) {
    StringCalculator calculator;
    EXPECT_EQ(calculator.Add("1,2"), 3);
}

TEST(StringCalculatorTest, HandlesNewLineAsDelimiter) {
    StringCalculator calculator;
    EXPECT_EQ(calculator.Add("1\n2,3"), 6);
}

TEST(StringCalculatorTest, SupportsCustomDelimiter) {
    StringCalculator calculator;
    EXPECT_EQ(calculator.Add("//;\n1;2"), 3);
}

TEST(StringCalculatorTest, ThrowsExceptionForNegativeNumbers) {
    StringCalculator calculator;
    EXPECT_THROW(calculator.Add("1,-2,-3"), std::runtime_error);
}

TEST(StringCalculatorTest, IgnoresNumbersGreaterThan1000) {
    StringCalculator calculator;
    EXPECT_EQ(calculator.Add("2,1001"), 2);
}

TEST(StringCalculatorTest, SupportsCustomDelimiterWithAnyLength) {
    StringCalculator calculator;
    EXPECT_EQ(calculator.Add("//[***]\n1***2***3"), 6);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
