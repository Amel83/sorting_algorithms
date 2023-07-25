#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * merge - Merges two sub-arrays.
 * @array: Pointer.
 * @left: the left sub-array.
 * @right: the right sub-array.
 * @s_left: Size of left sub-array.
 * @s_right: Size the right sub-array.
 */

void merge(int *array, int *left, int *right,
		size_t s_left, size_t s_right)
{
	size_t m = 0, n = 0, k = 0;
	int *temp = malloc((s_left + s_right) * sizeof(int));

	if (temp == NULL)
		return;
	printf("Merging...\n[left]: ");
	print_array(left, s_left);
	printf("[right]: ");
	print_array(right, s_right);
	while (m < s_left && n < s_right)
	{
		if (left[m] <= right[n])
		{
			temp[k] = left[m];
			m++;
		}
		else
		{
			temp[k] = right[n];
			n++;
		}
		k++;
	}
	while (m < s_left)
	{
		temp[k] = left[m];
		m++;
		k++;
	}
	while (n < s_right)
	{
		temp[k] = right[n];
		n++;
		k++;
	}
	for (m = 0; m < s_left + s_right; m++)
		array[m] = temp[m];
	printf("[Done]: ");
	print_array(array, s_left + s_right);
	free(temp);
}

/**
 * merge_sort - Merge Sort algorithm.
 * @array: Pointer.
 * @size: Size of the array.
 */

void merge_sort(int *array, size_t size)
{
	size_t middle = size / 2;
	size_t s_left = middle;
	size_t s_right = size - middle;
	int *left = array;
	int *right = array + middle;

	if (array == NULL || size <= 1)
		return;
	merge_sort(left, s_left);
	merge_sort(right, s_right);
	merge(array, left, right, s_left, s_right);
}
