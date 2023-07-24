#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * merge - Merges two sub-arrays into a sorted array.
 * @array: Pointer to the original array.
 * @left: Pointer to the left sub-array.
 * @right: Pointer to the right sub-array.
 * @size_left: Size of the left sub-array.
 * @size_right: Size of the right sub-array.
 */
void merge(int *array, int *left, int *right, size_t size_left, size_t size_right)
{
	size_t i = 0, j = 0, k = 0;
	int *tmp = malloc((size_left + size_right) * sizeof(int));

	if (tmp == NULL)
		return;
	printf("Merging...\n[left]: ");
	print_array(left, size_left);
	printf("[right]: ");
	print_array(right, size_right);
	while (i < size_left && j < size_right)
	{
		if (left[i] <= right[j])
		{
			tmp[k] = left[i];
			i++;
		}
		else
		{
			tmp[k] = right[j];
			j++;
		}
		k++;
	}
	while (i < size_left)
	{
		tmp[k] = left[i];
		i++;
		k++;
	}
	while (j < size_right)
	{
		tmp[k] = right[j];
		j++;
		k++;
	}
	for (i = 0; i < size_left + size_right; i++)
		array[i] = tmp[i];
	printf("[Done]: ");
	print_array(array, size_left + size_right);
	free(tmp);
}

/**
 * merge_sort - Merge Sort algorithm.
 * @array: Pointer to the array of integers.
 * @size: Size of the array.
 */
void merge_sort(int *array, size_t size)
{
	size_t middle = size / 2;
	size_t size_left = middle;
	size_t size_right = size - middle;
	int *left = array;
	int *right = array + middle;

	if (array == NULL || size <= 1)
		return;
	merge_sort(left, size_left);
	merge_sort(right, size_right);
	merge(array, left, right, size_left, size_right);
}
