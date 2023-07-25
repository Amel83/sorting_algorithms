#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * sift_down - Perform the sift-down operation to maintain the heap property.
 */
void sift_down(int *array, size_t size, size_t start, size_t end)
{
	int temp;
    size_t child, swap, root = start;

    while ((2 * root + 1) <= end) {
        child = 2 * root + 1;
        swap = root;

        if (array[swap] < array[child])
            swap = child;

        if (child + 1 <= end && array[swap] < array[child + 1])
            swap = child + 1;

        if (swap == root)
            return;

        temp = array[root];
        array[root] = array[swap];
        array[swap] = temp;

        print_array(array, size);

        root = swap;
    }
}

/**
 * heap_sort - Sorts an array of integers in ascending order using the
 *             Heap sort algorithm.
 */
void heap_sort(int *array, size_t size)
{
	int i, temp;
    if (array == NULL || size <= 1)
        return;

    /* Build max heap */
    for (i = size / 2 - 1; i >= 0; i--)
        sift_down(array, size, i, size - 1);

    /* Heap sort */
    for (i = size - 1; i > 0; i--) {
        temp = array[0];
        array[0] = array[i];
        array[i] = temp;

        print_array(array, size);

        sift_down(array, size, 0, i - 1);
    }
}

