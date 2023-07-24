#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * counting_sort - Sorts an array of integers in ascending order using the
 *                 Counting Sort algorithm.
 * @array: Pointer to the array of integers.
 * @size: Size of the array.
 */
void counting_sort(int *array, size_t size)
{
	int i, max = 0;
	int *count_array = NULL, *output = NULL;

	if (array == NULL || size <= 1)
		return;
	for (i = 0; i < (int)size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	count_array = calloc((max + 1), sizeof(int));
	if (count_array == NULL)
		return;
	for (i = 0; i <= max; i++)
		count_array[i] = 0;
	for (i = 0; i < (int)size; i++)
		count_array[array[i]]++;
	for (i = 1; i <= max; i++)
	{
		count_array[i] += count_array[i - 1];
	}
	print_array(count_array, max + 1);
	output = malloc(size * sizeof(int));
	if (output == NULL)
	{
		free(count_array);
		return;
	}
	for (i = size - 1; i >= 0; i--)
	{
		count_array[array[i]]--;
		output[count_array[array[i]]] = array[i];
	}
	for (i = 0; i < (int)size; i++)
	{
		array[i] = output[i];
	}
	free(count_array);
	free(output);
}
