// #include <string.h>
// #include<stdlib.h>
// // ExpectZeroForEmptyInput, ExpectZeroForSingleZero  
// bool isemptystring(const char* value)
// {
//     if (value == NULL || value[0] == '\0')
//     {
//         return 1;
//     }
//     return 0;
// }

// int islessthanthousand(const char *val)
// {    
//     int sum = 0;
//     int input = atoi(val); // string to int
//     if(input < 1000)
//     {
//         sum += input;
//         return sum;
//     }
//     return 0;
     
// }

// int calculatesum(const char* input, char* delimiter)
// {
//     int sum = 0;
//     char* duplicate_input = NULL;
//     duplicate_input = strdup (input); // duplicate the string 
//     char* token = strtok(duplicate_input,delimiter); //tokenizing strings
//     while(token != NULL)
//     {
//         sum = sum + islessthanthousand(token);
//         token = strtok(NULL,delimiter);
//     }
//     return sum;
// }

// void append_custom_delimiter(const char* input, char* delimiter) {
//     int i = 2; 
//     while(input[i] != '\n')
//     {
//         char src[1] = {input[i]};
//         strncat (delimiter, src,1);
//         i = i+1;
//     }
// }
// //ExpectSumWithCustomDelimiter("//;\n1;2")
// void checkcustomdelimiter(const char* input, char* delimiter)
// {
//     if (input[0] == '/' && input[1] == '/')
//     {
//         strcpy(delimiter, "");
//         append_custom_delimiter(input,delimiter);
//     }
//     else
//     {
//         delimiter = ",\n";
//     }
// }
// //ExpectSumWithCustomDelimiter
// int add (const char* input)
// {
//     char delimiter[128] = ",\n";
//     if (1 == isemptystring(input))
//     {
//         return 0;
//     }
//     checkcustomdelimiter(input, delimiter);
//     return calculatesum(input, delimiter);
    
// }
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

bool isemptystring(const char* value) {
    return value == NULL || value[0] == '\0';
}

int parse_number(const char* val) {
    int num = atoi(val);
    return (num < 1000) ? num : 0;
}

int calculatesum(const char* input, const char* delimiter) {
    int sum = 0;
    char* copy = strdup(input); 
    char* token = strtok(copy, delimiter);

    while (token != NULL) {
        sum += parse_number(token);
        token = strtok(NULL, delimiter);
    }

    free(copy);
    return sum;
}

void extract_custom_delimiter(const char* input, char* delimiter) {
    int i = 2;
    while (input[i] != '\n' && input[i] != '\0') {
        delimiter[i - 2] = input[i];
        i++;
    }
    delimiter[i - 2] = '\0';
}

void checkcustomdelimiter(const char* input, char* delimiter) {
    if (input[0] == '/' && input[1] == '/') {
        extract_custom_delimiter(input, delimiter);
    } else {
        strcpy(delimiter, ",\n");
    }
}

int add(const char* input) {
    char delimiter[128] = ",\n";
    if (isemptystring(input)) {
        return 0;
    }

    checkcustomdelimiter(input, delimiter);
    const char* numbers_start = (input[0] == '/' && input[1] == '/') ? strchr(input, '\n') + 1 : input;
    return calculatesum(numbers_start, delimiter);
}
