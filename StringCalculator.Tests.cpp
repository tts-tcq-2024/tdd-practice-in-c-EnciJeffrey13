// #include <gtest/gtest.h>
// #include "StringCalculator.h"

// TEST(StringCalculatorAddTests, ExpectZeroForEmptyInput) {
//     int expectedresult = 0;
//     const char* input = "";
//     int result = add(input);
//     ASSERT_EQ(result, expectedresult);
// }

// TEST(StringCalculatorAddTests, ExpectZeroForSingleZero) {
//     int expectedresult = 0;
//     const char* input = "0";
//     int result = add(input);
//     ASSERT_EQ(result, expectedresult);
// }

// TEST(StringCalculatorAddTests, ExpectSumForTwoNumbers) {
//     int expectedresult = 3;
//     const char*  input = "1,2";
//     int result = add(input);
//     ASSERT_EQ(result, expectedresult);
// }

// TEST(StringCalculatorAddTests, ExpectSumWithNewlineDelimiter) {
//     int expectedresult = 6;
//     const char*  input = "1\n2,3";
//     int result =add(input);
//     ASSERT_EQ(result, expectedresult);
// }

// TEST(StringCalculatorAddTests, IgnoreNumbersGreaterThan1000) {
//     int expectedresult = 1;
//     const char*  input = "1,1001";
//     int result =add(input);
//     ASSERT_EQ(result, expectedresult);
// }

// TEST(StringCalculatorAddTests, ExpectSumWithCustomDelimiter) {
//     int expectedresult = 3;
//     const char*  input = "//;\n1;2";
//     int result = add(input);
//     ASSERT_EQ(result, expectedresult);
// }

#include <gtest/gtest.h>
extern "C" {
    #include "StringCalculator.h"
}

TEST(StringCalculatorAddTests, ExpectZeroForEmptyInput) {
    int expected_result = 0;
    const char* input = "";
    int result = add(input);
    ASSERT_EQ(result, expected_result);
}

TEST(StringCalculatorAddTests, ExpectZeroForSingleZero) {
    int expected_result = 0;
    const char* input = "0";
    int result = add(input);
    ASSERT_EQ(result, expected_result);
}

TEST(StringCalculatorAddTests, ExpectSumForTwoNumbers) {
    int expected_result = 3;
    const char* input = "1,2";
    int result = add(input);
    ASSERT_EQ(result, expected_result);
}

TEST(StringCalculatorAddTests, ExpectSumWithNewlineDelimiter) {
    int expected_result = 6;
    const char* input = "1\n2,3";
    int result = add(input);
    ASSERT_EQ(result, expected_result);
}

TEST(StringCalculatorAddTests, IgnoreNumbersGreaterThan1000) {
    int expected_result = 1;
    const char* input = "1,1001";
    int result = add(input);
    ASSERT_EQ(result, expected_result);
}

TEST(StringCalculatorAddTests, ExpectSumWithCustomDelimiter) {
    int expected_result = 3;
    const char* input = "//;\n1;2";
    int result = add(input);
    ASSERT_EQ(result, expected_result);
}

TEST(StringCalculatorAddTests, ExpectExceptionForNegativeNumbers) {
    const char* input = "1,-3,-4";
    ASSERT_EXIT(add(input), ::testing::ExitedWithCode(EXIT_FAILURE), "negatives not allowed: -3 -4 ");
}

TEST(StringCalculatorAddTests, ExpectSumWithEmptyString) {
    int expected_result = 0;
    const char* input = "";
    int result = add(input);
    ASSERT_EQ(result, expected_result);
}

TEST(StringCalculatorAddTests, ExpectSumWithSingleNumber) {
    int expected_result = 5;
    const char* input = "5";
    int result = add(input);
    ASSERT_EQ(result, expected_result);
}

TEST(StringCalculatorAddTests, ExpectSumWithMixedDelimiters) {
    int expected_result = 6;
    const char* input = "1\n2,3";
    int result = add(input);
    ASSERT_EQ(result, expected_result);
}

TEST(StringCalculatorAddTests, ExpectSumWithCustomDelimiterAtStart) {
    int expected_result = 0;
    const char* input = "/2";
    int result = add(input);
    ASSERT_EQ(result, expected_result);
}

TEST(StringCalculatorAddTests, ExpectSumWithMultipleCustomDelimiters) {
    int expected_result = 6;
    const char* input = "//[;][#]\n1;2#3";
    int result = add(input);
    ASSERT_EQ(result, expected_result);
}

TEST(StringCalculatorAddTests, ExpectSumWithCustomDelimiterOfMoreThanOneCharacter) {
    int expected_result = 6;
    const char* input = "//[***]\n1***2***3";
    int result = add(input);
    ASSERT_EQ(result, expected_result);
}

TEST(StringCalculatorAddTests, ExpectSumWithEmptyLinesBetweenNumbers) {
    int expected_result = 6;
    const char* input = "1\n\n2,3";
    int result = add(input);
    ASSERT_EQ(result, expected_result);
}

TEST(StringCalculatorAddTests, ExpectSumWithCustomDelimiterContainingSpecialCharacters) {
    int expected_result = 6;
    const char* input = "//[.]\n1.2.3";
    int result = add(input);
    ASSERT_EQ(result, expected_result);
}

TEST(StringCalculatorAddTests, ExpectZeroWithEmptyCustomDelimiterLine) {
    int expected_result = 0;
    const char* input = "//\n";
    int result = add(input);
    ASSERT_EQ(result, expected_result);
}

TEST(StringCalculatorAddTests, ExpectSumWithCustomDelimiterSameAsDefaultDelimiter) {
    int expected_result = 6;
    const char* input = "//,\n1,2,3";
    int result = add(input);
    ASSERT_EQ(result, expected_result);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
