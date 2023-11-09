//
// Created by Surya on 27-09-2023.
/**
 * @file utils_array.h
 * @brief A collection of functions definition for working with arrays.
 */

#include "utils_array.h"
#include <stdlib.h>
#include <stdio.h>
/**
 * @brief Calculates the sum of all elements in an array.
 *
 * This function takes an array of floating-point numbers and its length and
 * returns the sum of all elements in the array.
 *
 * @param arr The input array of floating-point numbers.
 * @param len The length of the input array.
 * @return The sum of all elements in the array.
 */

float Arrays_sum(const float arr[], int len) {
    float sum = 0;
    for (int i = 0; i < len; ++i) {
        sum += arr[i];
    }
    return sum;
}

/**
 * @brief Finds the maximum element in an array.
 *
 * This function takes an array of floating-point numbers and its length and
 * returns the maximum element in the array.
 *
 * @param arr The input array of floating-point numbers.
 * @param n The length of the input array.
 * @return The maximum element in the array.
 */

float Arrays_maxOf(const float *arr, int n) {
    float maximum = arr[0];
    for (int i = 1; i < n; ++i) {
        if (arr[i] > maximum) {
            maximum = arr[i];
        }
    }
    return maximum;
}

/**
 * @brief Converts an array to a string.
 *
 * This function converts an array of integers to a string format. The resulting
 * string represents the elements of the array enclosed in square brackets.
 *
 * @param arr The input array of integers.
 * @param n The length of the input array.
 * @return A dynamically allocated string representing the array.
 */

char *Arrays_toString(const int *arr, int n) {
    char *ch = (char*)(malloc(200));
    ch[0] = '[';
    ch[1] = '\0';
    int count;
    if (n == 0) {
        count = snprintf(ch, 2000, "%s%s", ch, "NULL");
        ch[count] = ']';
        ch[count + 1] = '\0';
    } else {
        for (int i = 0; i < n; i = i + 1) {
            count = snprintf(ch, 2000, "%s%d, ", ch, arr[i]);
        }
        ch[count - 2] = ']';
        ch[count - 1] = '\0';
    }
    return ch;
}