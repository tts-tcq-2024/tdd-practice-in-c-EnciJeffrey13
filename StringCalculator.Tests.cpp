// #include <gtest/gtest.h>
//  #include "StringCalculator.h"

// // Test case for empty string input
// TEST(StringCalculatorTest, HandlesEmptyString) {
//     ASSERT_EQ(add(""), 0);
// }

// // Test case for single number input
// TEST(StringCalculatorTest, HandlesSingleNumber) {
//     ASSERT_EQ(add("5"), 5);
// }

// // Test case for two numbers input separated by a comma
// TEST(StringCalculatorTest, HandlesTwoNumbersComma) {
//     ASSERT_EQ(add("1,2"), 3);
// }

// // Test case for multiple numbers input separated by a comma
// TEST(StringCalculatorTest, HandlesMultipleNumbersComma) {
//     ASSERT_EQ(add("1,2,3,4"), 10);
// }

// // Test case for numbers with newlines between them
// TEST(StringCalculatorTest, HandlesNewlineBetweenNumbers) {
//     ASSERT_EQ(add("1\n2,3"), 6);
// }

// // Test case for custom single-character delimiter
// TEST(StringCalculatorTest, HandlesCustomSingleCharacterDelimiter) {
//     ASSERT_EQ(add("//;\n1;2;3"), 6);
// }

// // Test case for custom multi-character delimiter
// TEST(StringCalculatorTest, HandlesCustomMultiCharacterDelimiter) {
//     ASSERT_EQ(add("//[***]\n1***2***3"), 6);
// }

// // Test case for numbers larger than 1000 being ignored
// TEST(StringCalculatorTest, IgnoresNumbersLargerThan1000) {
//     ASSERT_EQ(add("2,1001"), 2);
//     ASSERT_EQ(add("//;\n1002;1003;4"), 4);
// }

// // Test case for multiple custom delimiters
// TEST(StringCalculatorTest, HandlesMultipleCustomDelimiters) {
//     ASSERT_EQ(add("//[*][%]\n1*2%3"), 6);
// }

// // Test case for custom delimiters with special characters
// TEST(StringCalculatorTest, HandlesCustomDelimitersWithSpecialCharacters) {
//     ASSERT_EQ(add("//[***][%%]\n1***2%%3"), 6);
// }

// // Test case for negative numbers throwing an error
// TEST(StringCalculatorTest, ThrowsErrorOnNegativeNumbers) {
//     ASSERT_EXIT(add("1,-2,3,-4"), ::testing::ExitedWithCode(EXIT_FAILURE), "negatives not allowed: -2,-4");
// }

// // Test case for input with no valid numbers
// TEST(StringCalculatorTest, HandlesNoValidNumbers) {
//     ASSERT_EQ(add("1001,1002,1003"), 0);
// }

// // Test case for custom delimiter at the beginning of input with no numbers
// TEST(StringCalculatorTest, HandlesCustomDelimiterWithNoNumbers) {
//     ASSERT_EQ(add("//;\n"), 0);
// }

// // Additional test case for getDelimiter to handle custom delimiter with correct syntax
// TEST(StringCalculatorTest, HandlesCustomDelimiterWithCorrectSyntax) {
//     char input[] = "//;\n1;2";
//     char* input_ptr = input;
//     char* delimiter = getDelimiter(&input_ptr);
//     ASSERT_STREQ(delimiter, ";");
//     free(delimiter);
// }

// // Additional test case for getDelimiter to handle default delimiter
// TEST(StringCalculatorTest, HandlesDefaultDelimiter) {
//     char input[] = "1,2,3";
//     char* input_ptr = input;
//     char* delimiter = getDelimiter(&input_ptr);
//     ASSERT_STREQ(delimiter, ",");
//     free(delimiter);
// }

// // Additional test case for isInputValid with NULL input
// TEST(StringCalculatorTest, HandlesNullInput) {
//     ASSERT_EQ(isInputValid(NULL), 0);
// }

// // Additional test case for isInputValid with empty input
// TEST(StringCalculatorTest, HandlesEmptyInput) {
//     ASSERT_EQ(isInputValid(""), 0);
// }

// // Additional test case for isInputValid with valid input
// TEST(StringCalculatorTest, HandlesValidInput) {
//     ASSERT_EQ(isInputValid("1,2,3"), 1);
// }

// // Additional test case for checkForNegatives with no negatives
// TEST(StringCalculatorTest, HandlesNoNegatives) {
//     char negatives[] = "";
//     ASSERT_NO_THROW(checkForNegatives(negatives));
// }

// // Additional test case for checkForNegatives with negatives

// TEST(StringCalculatorTest, ThrowsErrorWithNegativesCheck) {
//     char negatives[] = "-1,-2,";
//     ASSERT_EXIT(checkForNegatives(negatives), 
//                 ::testing::ExitedWithCode(EXIT_FAILURE), 
//                 "negatives not allowed: -1,-2");
// }


// // Additional test case for custom delimiter without newline (edge case)
// TEST(StringCalculatorTest, HandlesCustomDelimiterWithoutNewline) {
//     char input[] = "//,1,2";
//     char* input_ptr = input;
//     char* delimiter = getDelimiter(&input_ptr);
//     ASSERT_STREQ(delimiter, ",");
//     free(delimiter);
// }
#include <gtest/gtest.h>
#include "StringCalculator.h"

// Test case for empty string input
TEST(StringCalculatorTest, HandlesEmptyString) {
    ASSERT_EQ(calculateSum(""), 0);
}

// Test case for single number input
TEST(StringCalculatorTest, HandlesSingleNumber) {
    ASSERT_EQ(calculateSum("5"), 5);
}

// Test case for two numbers input separated by a comma
TEST(StringCalculatorTest, HandlesTwoNumbersComma) {
    ASSERT_EQ(calculateSum("1,2"), 3);
}

// Test case for multiple numbers input separated by a comma
TEST(StringCalculatorTest, HandlesMultipleNumbersComma) {
    ASSERT_EQ(calculateSum("1,2,3,4"), 10);
}

// Test case for numbers with newlines between them
TEST(StringCalculatorTest, HandlesNewlineBetweenNumbers) {
    ASSERT_EQ(calculateSum("1\n2,3"), 6);
}

// Test case for custom single-character delimiter
TEST(StringCalculatorTest, HandlesCustomSingleCharacterDelimiter) {
    ASSERT_EQ(calculateSum("//;\n1;2;3"), 6);
}

// Test case for custom multi-character delimiter
TEST(StringCalculatorTest, HandlesCustomMultiCharacterDelimiter) {
    ASSERT_EQ(calculateSum("//[***]\n1***2***3"), 6);
}

// Test case for numbers larger than 1000 being ignored
TEST(StringCalculatorTest, IgnoresNumbersLargerThan1000) {
    ASSERT_EQ(calculateSum("2,1001"), 2);
    ASSERT_EQ(calculateSum("//;\n1002;1003;4"), 4);
}

// Test case for multiple custom delimiters
TEST(StringCalculatorTest, HandlesMultipleCustomDelimiters) {
    ASSERT_EQ(calculateSum("//[*][%]\n1*2%3"), 6);
}

// Test case for custom delimiters with special characters
TEST(StringCalculatorTest, HandlesCustomDelimitersWithSpecialCharacters) {
    ASSERT_EQ(calculateSum("//[***][%%]\n1***2%%3"), 6);
}

// Test case for negative numbers throwing an error
TEST(StringCalculatorTest, ThrowsErrorOnNegativeNumbers) {
    ASSERT_EXIT(calculateSum("1,-2,3,-4"), ::testing::ExitedWithCode(EXIT_FAILURE), "Negatives not allowed: -2,-4");
}

// Test case for input with no valid numbers
TEST(StringCalculatorTest, HandlesNoValidNumbers) {
    ASSERT_EQ(calculateSum("1001,1002,1003"), 0);
}

// Test case for custom delimiter at the beginning of input with no numbers
TEST(StringCalculatorTest, HandlesCustomDelimiterWithNoNumbers) {
    ASSERT_EQ(calculateSum("//;\n"), 0);
}

// Additional test case for extractDelimiter to handle custom delimiter with correct syntax
TEST(StringCalculatorTest, HandlesCustomDelimiterWithCorrectSyntax) {
    char input[] = "//;\n1;2";
    char* input_ptr = input;
    char* delimiter = extractDelimiter(&input_ptr);
    ASSERT_STREQ(delimiter, ";");
    free(delimiter);
}

// Additional test case for extractDelimiter to handle default delimiter
TEST(StringCalculatorTest, HandlesDefaultDelimiter) {
    char input[] = "1,2,3";
    char* input_ptr = input;
    char* delimiter = extractDelimiter(&input_ptr);
    ASSERT_STREQ(delimiter, ",");
    free(delimiter);
}

// Additional test case for validateInput with NULL input
TEST(StringCalculatorTest, HandlesNullInput) {
    ASSERT_EQ(validateInput(NULL), 0);
}

// Additional test case for validateInput with empty input
TEST(StringCalculatorTest, HandlesEmptyInput) {
    ASSERT_EQ(validateInput(""), 0);
}

// Additional test case for validateInput with valid input
TEST(StringCalculatorTest, HandlesValidInput) {
    ASSERT_EQ(validateInput("1,2,3"), 1);
}

// Additional test case for handleNegatives with no negatives
TEST(StringCalculatorTest, HandlesNoNegatives) {
    char negatives[] = "";
    ASSERT_NO_THROW(handleNegatives(negatives));
}

// Additional test case for handleNegatives with negatives
TEST(StringCalculatorTest, ThrowsErrorWithNegativesCheck) {
    char negatives[] = "-1,-2,";
    ASSERT_EXIT(handleNegatives(negatives), 
                ::testing::ExitedWithCode(EXIT_FAILURE), 
                "Negatives not allowed: -1,-2");
}

// Additional test case for extractDelimiter without newline (edge case)
TEST(StringCalculatorTest, HandlesCustomDelimiterWithoutNewline) {
    char input[] = "//,1,2";
    char* input_ptr = input;
    char* delimiter = extractDelimiter(&input_ptr);
    ASSERT_STREQ(delimiter, ",");
    free(delimiter);
}
