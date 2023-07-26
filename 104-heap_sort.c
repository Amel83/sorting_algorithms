#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * _down - Perform the sift-down operation to maintain the heap property.
 * @array: pointer
 * @size: size of pointer
 * @start:starting
 * @end: ending
 **/

void _down(int *array, size_t size, size_t start, size_t end)
{
	int temp;
	size_t c, swap, root = start;

	while ((2 * root + 1) <= end)
	{
		c = 2 * root + 1;
		swap = root;
		if (array[swap] < array[c])
			swap = c;
		if (c + 1 <= end && array[swap] < array[c + 1])
			swap = c + 1;
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
 * heap_sort - Heap sort algorithm.
 * @array: pointer
 * @size: size
 */

void heap_sort(int *array, size_t size)
{
	int j, ptr;

	if (array == NULL || size <= 1)
		return;
	for (j = size / 2 - 1; j >= 0; j--)
		_down(array, size, j, size - 1);
	for (j = size - 1; j > 0; j--)
	{
		ptr = array[0];
		array[0] = array[j];
		array[j] = ptr;
		print_array(array, size);
		_down(array, size, 0, j - 1);
	}
}

