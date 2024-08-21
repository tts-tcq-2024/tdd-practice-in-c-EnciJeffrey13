#ifndef STRING_CALCULATOR_H
#define STRING_CALCULATOR_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

int add(const char* input);

static bool has_custom_delimiter(const char* input) {
    return input[0] == '/' && input[1] == '/';
}

static void extract_custom_delimiter(const char* input, char* delimiter) {
    const char* start = input + 2; // Skip over "//"
    size_t length = strcspn(start, "\n"); // Find the position of the newline character
    strncpy(delimiter, start, length); // Copy the delimiter
    delimiter[length] = '\0'; // Null-terminate the delimiter
}

static void split_numbers(const char* input, const char* delimiters, int* numbers, int* count) {
    char* copy = strdup(input);
    char* token = strtok(copy, delimiters);
    while (token) {
        numbers[(*count)++] = atoi(token);
        token = strtok(NULL, delimiters);
    }
    free(copy);
}

static bool check_negatives(int* numbers, int count, char* message) {
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

static int calculate_sum(int* numbers, int count) {
    int sum = 0;
    for (int i = 0; i < count; i++) {
        if (numbers[i] <= 1000) {
            sum += numbers[i];
        }
    }
    return sum;
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

    int numbers[1000];
    int count = 0;
    split_numbers(numbers_start, delimiter, numbers, &count);

    char message[256];
    if (check_negatives(numbers, count, message)) {
        fprintf(stderr, "%s\n", message);
        exit(EXIT_FAILURE);
    }

    return calculate_sum(numbers, count);
}

#endif // STRING_CALCULATOR_H
