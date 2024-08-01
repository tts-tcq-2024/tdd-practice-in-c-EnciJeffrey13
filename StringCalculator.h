#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>
#include "StringCalculator.h"

/* Mock function for the add function (if needed) */
int add(const char* input) {
    return mock_type(int);
}

static void test_empty_input(void **state) {
    (void) state; // Unused variable
    assert_int_equal(add(""), 0);
}

static void test_single_zero(void **state) {
    (void) state; // Unused variable
    assert_int_equal(add("0"), 0);
}

static void test_two_numbers(void **state) {
    (void) state; // Unused variable
    assert_int_equal(add("1,2"), 3);
}

static void test_newline_delimiter(void **state) {
    (void) state; // Unused variable
    assert_int_equal(add("1\n2,3"), 6);
}

static void test_ignore_numbers_greater_than_1000(void **state) {
    (void) state; // Unused variable
    assert_int_equal(add("1,1001"), 1);
}

static void test_custom_delimiter(void **state) {
    (void) state; // Unused variable
    assert_int_equal(add("//;\n1;2"), 3);
}

int main(void) {
    const struct CMUnitTest tests[] = {
        cmocka_unit_test(test_empty_input),
        cmocka_unit_test(test_single_zero),
        cmocka_unit_test(test_two_numbers),
        cmocka_unit_test(test_newline_delimiter),
        cmocka_unit_test(test_ignore_numbers_greater_than_1000),
        cmocka_unit_test(test_custom_delimiter),
    };
    
    return cmocka_run_group_tests(tests, NULL, NULL);
}
// #include <stdio.h>
// #include <string.h>
// #include <stdlib.h>
// #include <stdexcept>

// int add_arr(int *arr,int cnt)
// {
//     int i = 0;
//     int total = 0;
//     while(i < cnt)
//     {
//         if(arr[i] < 1000)
//         {
//           total += arr[i];
//         }
//         i++;
//     }
 
//     return total;
// }
 
 
// int check_num(const char ch)
// {
//     if(ch >= '0' && ch <= '9')
//     {
//         return 1;
//     }
//     return 0;
// }
 
// void strtonum(const char* ch, int *num_arr,int *cnt)
// {
//     static int num = 0;
 
//     if(check_num(ch[*cnt]))
//     {
//        num = num * 10 + ch[*cnt] - '0';
//        if(check_num(ch[(*cnt)+1]))
//        {
//            (*cnt)++;
//        }
//        else
//        {
//           num_arr[*cnt] = num;
//           num = 0;
//           (*cnt)++;
//        }
//     }
//     else
//     {
//         (*cnt)++;
//         num = 0;
//     }
// }
 
// int sum(const char *ch)
// {
//     int cnt =0;
//     int total = 0;
//     int num_arr[100] = {0};
//     while(ch[cnt] != '\0')
//     {
//        strtonum(ch,num_arr,&cnt);
//     }
 
//     total = add_arr(num_arr,cnt);
 
//     return total;
// }
 
 
// int neg_loop(const char *ch,int i)
// {
//       if(ch[i] == '-')
//       {
//           if(check_num(ch[i+1]))
//           {
//               return 0;
//           }
//       }
//     return 1;
// }
 
// int check_neg(const char *ch)
// {
//     int res = 0,i=0;
//     while(ch[i] != '\0')
//     {
//       res = neg_loop(ch,i);
//       if(res == 0)
//       {
//           break;
//       }
//       i++;
//     }
//     return res;
// }
 
// int check_string(const char *ch)
// {
//     if(ch != NULL)
//     {
//        if(check_neg(ch))
//        {
//            return 1;
//        }
//     }
 
//     return 0;
// }
// int add(const char *ch)
// {
//     if(check_string(ch))
//     {
//         int total = sum(ch);
 
//         if(total > 0)
//         {
//             return total;
//         }
//         return 0;
//     }
 
//     return -1;
// }
