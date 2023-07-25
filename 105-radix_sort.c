#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * get_max - Returns the maximum.
 * @array: Pointer to the array.
 * @size: Size of the array.
 * Return: The maximum element.
 */

int get_max(int *array, size_t size)
{
	size_t j;
	int max = array[0];

	for (j = 1; j < size; j++)
	{
		if (array[j] > max)
			max = array[j];
	}
	return (max);
}

/**
 * counting_sort_radix - Sorts an array.
 * @array: Pointer to the array.
 * @size: Size of the array.
 * @exp: The current significant digit to sort.
 */

void counting_sort_radix(int *array, size_t size, int exp)
{
	int *i = malloc(size * sizeof(int));
	int count[10] = {0};
	size_t j;

	if (i == NULL)
		return;
	for (j = 0; j < size; j++)
		count[(array[j] / exp) % 10]++;
	for (j = 1; j < 10; j++)
		count[j] += count[j - 1];
	for (j = size - 1; (int)j >= 0; j--)
	{
		i[count[(array[j] / exp) % 10] - 1] = array[j];
		count[(array[j] / exp) % 10]--;
	}
	for (j = 0; j < size; j++)
		array[j] = i[j];
	free(i);
}

/**
 * radix_sort - Sorts an array of integers
 * @array: Pointer to the array.
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
