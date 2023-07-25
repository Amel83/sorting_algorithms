#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * merge - Merge two subarrays in either increasing or decreasing order.
 */
void merge(int *array, size_t start, size_t step, int order)
{
	int temp;
	size_t i;
    if (step < 1)
        return;

    for (i = start; i < start + step; i++) {
        if ((array[i] > array[i + step]) == order) {
            temp = array[i];
            array[i] = array[i + step];
            array[i + step] = temp;
        }
    }
}

/**
 * bitonic_sort_recursive - Recursive function to perform Bitonic sort.
 */
void bitonic_sort_recursive(int *array, size_t size, size_t start, size_t step, int order)
{
	size_t  mid = step / 2;
    if (step < 1)
        return;

    bitonic_sort_recursive(array, size, start, mid, !order);
    bitonic_sort_recursive(array, size, start + mid, mid, order);
    merge(array, start, step, order);
}

/**
 * bitonic_sort - Sorts an array of integers in ascending order using the
 *                Bitonic sort algorithm.
 */
void bitonic_sort(int *array, size_t size)
{
    if (array == NULL || size <= 1)
        return;

    bitonic_sort_recursive(array, size, 0, size, 1);
}

