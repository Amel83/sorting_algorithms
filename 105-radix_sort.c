#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * get_max - Returns the maximum element from the array.
 * @array: Pointer to the array of integers.
 * @size: Size of the array.
 * Return: The maximum element from the array.
 */
int get_max(int *array, size_t size)
{
    size_t i;
    int max = array[0];

    for (i = 1; i < size; i++)
    {
        if (array[i] > max)
            max = array[i];
    }

    return max;
}

/**
 * counting_sort_radix - Sorts an array of integers based on the digit.
 * @array: Pointer to the array of integers.
 * @size: Size of the array.
 * @exp: The current significant digit to sort by.
 */
void counting_sort_radix(int *array, size_t size, int exp)
{
    int *output = malloc(size * sizeof(int));
    int count[10] = {0};
    size_t i;

    if (output == NULL)
        return;

    for (i = 0; i < size; i++)
        count[(array[i] / exp) % 10]++;

    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for (i = size - 1; (int)i >= 0; i--)
    {
        output[count[(array[i] / exp) % 10] - 1] = array[i];
        count[(array[i] / exp) % 10]--;
    }

    for (i = 0; i < size; i++)
        array[i] = output[i];

    free(output);
}

/**
 * radix_sort - Sorts an array of integers in ascending order using the
 *              Radix Sort algorithm (LSD).
 * @array: Pointer to the array of integers.
 * @size: Size of the array.
 */
void radix_sort(int *array, size_t size)
{
    int max = get_max(array, size);
    int exp;

    for (exp = 1; max / exp > 0; exp *= 10)
    {
        counting_sort_radix(array, size, exp);
        print_array(array, size);
    }
}

