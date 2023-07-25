#include <stdio.h>
#include "sort.h"

/**
 * selection_sort - Sorting.
 * @array: Pointer to the array.
 * @size: Size of the array.
 */

void selection_sort(int *array, size_t size)
{
	int temp;
	size_t i, k index;

	if (array == NULL || size < 2)
		return;
	for (i = 0; i < size - 1; i++)
	{
		index = i;
		for (k = i + 1; k < size; k++)
		{
			if (array[k] < array[index])
				index = k;
		}
		if (index != i)
		{
			temp = array[i];
			array[i] = array[index];
			array[index] = temp;
			print_array(array, size);
		}
	}
}
