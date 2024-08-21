#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool has_custom_delimiter(const char* input) {
    return strncmp(input, "//", 2) == 0;
}

const char* extract_custom_delimiter(const char* input, char* delimiter) {
    const char* delimiter_end = strchr(input + 2, '\n');
    size_t length = delimiter_end - (input + 2);
    strncpy(delimiter, input + 2, length);
    delimiter[length] = '\0';
    return delimiter_end + 1;
}

int parse_number(const char* token, char* negatives) {
    int num = atoi(token);
    if (num < 0) {
        sprintf(negatives + strlen(negatives), "%d ", num);
    }
    return num;
}

int split_and_sum(const char* input, const char* delimiters, char* negatives) {
    int sum = 0;
    char* copy = strdup(input);
    char* token = strtok(copy, delimiters);

    while (token) {
        int num = parse_number(token, negatives);
        if (num <= 1000) sum += num;
        token = strtok(NULL, delimiters);
    }

    free(copy);
    return sum;
}

int add(const char* input) {
    if (*input == '\0') return 0;

    char delimiter[100] = ",\n";
    const char* numbers_start = input;

    if (has_custom_delimiter(input)) {
        numbers_start = extract_custom_delimiter(input, delimiter);
    }

    char negatives[256] = "negatives not allowed: ";
    int sum = split_and_sum(numbers_start, delimiter, negatives);

    if (strlen(negatives) > strlen("negatives not allowed: ")) {
        fprintf(stderr, "%s\n", negatives);
        exit(EXIT_FAILURE);
    }

    return sum;
}
