#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * counting_sort - Sorts an array.
 * @array: Pointer to the array.
 * @size: Size of the array.
 */

void counting_sort(int *array, size_t size)
{
	int j, max = 0;
	int *count_array = NULL, *b = NULL;

	if (array == NULL || size <= 1)
		return;
	for (j = 0; j < (int)size; j++)
	{
		if (array[j] > max)
			max = array[j];
	}
	count_array = calloc((max + 1), sizeof(int));
	if (count_array == NULL)
		return;
	for (j = 0; j <= max; j++)
		count_array[j] = 0;
	for (j = 0; j < (int)size; j++)
		count_array[array[j]]++;
	for (j = 1; j <= max; j++)
	{
		count_array[j] += count_array[j - 1];
	}
	print_array(count_array, max + 1);
	b = malloc(size * sizeof(int));
	if (b == NULL)
	{
		free(count_array);
		return;
	}
	for (j = size - 1; j >= 0; j--)
	{
		count_array[array[j]]--;
		b[count_array[array[j]]] = array[j];
	}
	for (j = 0; j < (int)size; j++)
	{
		array[j] = b[j];
	}
	free(count_array);
	free(b);
}
