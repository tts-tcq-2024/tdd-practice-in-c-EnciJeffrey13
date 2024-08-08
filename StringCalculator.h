// #include <stdarg.h>
// #include <stddef.h>
// #include <setjmp.h>
// #include <cmocka.h>
// #include "StringCalculator.h"

// /* Mock function for the add function (if needed) */
// int add(const char* input) {
//     return mock_type(int);
// }

// static void test_empty_input(void **state) {
//     (void) state; // Unused variable
//     assert_int_equal(add(""), 0);
// }

// static void test_single_zero(void **state) {
//     (void) state; // Unused variable
//     assert_int_equal(add("0"), 0);
// }

// static void test_two_numbers(void **state) {
//     (void) state; // Unused variable
//     assert_int_equal(add("1,2"), 3);
// }

// static void test_newline_delimiter(void **state) {
//     (void) state; // Unused variable
//     assert_int_equal(add("1\n2,3"), 6);
// }

// static void test_ignore_numbers_greater_than_1000(void **state) {
//     (void) state; // Unused variable
//     assert_int_equal(add("1,1001"), 1);
// }

// static void test_custom_delimiter(void **state) {
//     (void) state; // Unused variable
//     assert_int_equal(add("//;\n1;2"), 3);
// }

// int main(void) {
//     const struct CMUnitTest tests[] = {
//         cmocka_unit_test(test_empty_input),
//         cmocka_unit_test(test_single_zero),
//         cmocka_unit_test(test_two_numbers),
//         cmocka_unit_test(test_newline_delimiter),
//         cmocka_unit_test(test_ignore_numbers_greater_than_1000),
//         cmocka_unit_test(test_custom_delimiter),
//     };
    
//     return cmocka_run_group_tests(tests, NULL, NULL);
// }
// // #include <stdio.h>
// // #include <string.h>
// // #include <stdlib.h>
// // #include <stdexcept>

// // int add_arr(int *arr,int cnt)
// // {
// //     int i = 0;
// //     int total = 0;
// //     while(i < cnt)
// //     {
// //         if(arr[i] < 1000)
// //         {
// //           total += arr[i];
// //         }
// //         i++;
// //     }
 
// //     return total;
// // }
 
 
// // int check_num(const char ch)
// // {
// //     if(ch >= '0' && ch <= '9')
// //     {
// //         return 1;
// //     }
// //     return 0;
// // }
 
// // void strtonum(const char* ch, int *num_arr,int *cnt)
// // {
// //     static int num = 0;
 
// //     if(check_num(ch[*cnt]))
// //     {
// //        num = num * 10 + ch[*cnt] - '0';
// //        if(check_num(ch[(*cnt)+1]))
// //        {
// //            (*cnt)++;
// //        }
// //        else
// //        {
// //           num_arr[*cnt] = num;
// //           num = 0;
// //           (*cnt)++;
// //        }
// //     }
// //     else
// //     {
// //         (*cnt)++;
// //         num = 0;
// //     }
// // }
 
// // int sum(const char *ch)
// // {
// //     int cnt =0;
// //     int total = 0;
// //     int num_arr[100] = {0};
// //     while(ch[cnt] != '\0')
// //     {
// //        strtonum(ch,num_arr,&cnt);
// //     }
 
// //     total = add_arr(num_arr,cnt);
 
// //     return total;
// // }
 
 
// // int neg_loop(const char *ch,int i)
// // {
// //       if(ch[i] == '-')
// //       {
// //           if(check_num(ch[i+1]))
// //           {
// //               return 0;
// //           }
// //       }
// //     return 1;
// // }
 
// // int check_neg(const char *ch)
// // {
// //     int res = 0,i=0;
// //     while(ch[i] != '\0')
// //     {
// //       res = neg_loop(ch,i);
// //       if(res == 0)
// //       {
// //           break;
// //       }
// //       i++;
// //     }
// //     return res;
// // }
 
// // int check_string(const char *ch)
// // {
// //     if(ch != NULL)
// //     {
// //        if(check_neg(ch))
// //        {
// //            return 1;
// //        }
// //     }
 
// //     return 0;
// // }
// // int add(const char *ch)
// // {
// //     if(check_string(ch))
// //     {
// //         int total = sum(ch);
 
// //         if(total > 0)
// //         {
// //             return total;
// //         }
// //         return 0;
// //     }
 
// //     return -1;
// // }
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool has_custom_delimiter(const char* input) {
    return input[0] == '/' && input[1] == '/';
}

void extract_custom_delimiter(const char* input, char* delimiter) {
    const char* start = input + 2; // Skip over "//"
    size_t length = strcspn(start, "\n"); // Find the position of the newline character
    strncpy(delimiter, start, length); // Copy the delimiter
    delimiter[length] = '\0'; // Null-terminate the delimiter
}

void split_numbers(const char* input, const char* delimiters, int* numbers, int* count) {
    char* copy = strdup(input);
    char* token = strtok(copy, delimiters);
    while (token) {
        numbers[(*count)++] = atoi(token);
        token = strtok(NULL, delimiters);
    }
    free(copy);
}

bool check_negatives(int* numbers, int count, char* message) {
    bool has_negatives = false;
    strcpy(message, "negatives not allowed: ");
    for (int i = 0; i < count; i++) {
        if (numbers[i] < 0) {
            has_negatives = true;
            char num_str[12];
            snprintf(num_str, sizeof(num_str), "%d ", numbers[i]);
            strcat(message, num_str);
        }
    }
    return has_negatives;
}

int calculate_sum(int* numbers, int count) {
    int sum = 0;
    for (int i = 0; i < count; i++) {
        if (numbers[i] <= 1000) {
            sum += numbers[i];
        }
    }
    return sum;
}

int parse_and_calculate(const char* input, const char* delimiters) {
    int numbers[1000];
    int count = 0;
    split_numbers(input, delimiters, numbers, &count);

    char message[256];
    if (check_negatives(numbers, count, message)) {
        fprintf(stderr, "%s\n", message);
        exit(EXIT_FAILURE);
    }

    return calculate_sum(numbers, count);
}

int add(const char* input) {
    if (*input == '\0') {
        return 0;
    }

    char delimiter[100] = ",\n";
    const char* numbers_start = input;
    if (has_custom_delimiter(input)) {
        extract_custom_delimiter(input, delimiter);
        numbers_start = strchr(input, '\n') + 1; // Move past the delimiter line
    }

    return parse_and_calculate(numbers_start, delimiter);
}
