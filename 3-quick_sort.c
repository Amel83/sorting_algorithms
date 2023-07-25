#include <stdio.h>
#include "sort.h"

/**
 * quick_sort - sorting.
 * @array: Pointer to the array.
 * @size: Size of array.
 */

void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	quick_sort_recursive(array, 0, size - 1, size);
}

/**
 * quick_sort_recursive - Helper function.
 * @array: Pointer to the array.
 * @size: size
 * @low: Starting index of the partition to be sorted.
 * @high: Ending index of the partition.
 */
void quick_sort_recursive(int *array, int lw, int hg, size_t size)
{
	if (lw < hg)
	{
		int partition_idx = lomuto_partition(array, lw, hg, size);

		quick_sort_recursive(array, lw, partition_idx - 1, size);
		quick_sort_recursive(array, partition_idx + 1, hg, size);
	}
}

/**
 * lomuto_partition - Lomuto partition.
 * @array: Pointer to the array.
 * @size: size
 * @lw: Starting index of the partition.
 * @hg: Ending index of the partition.
 * Return: Index of the pivot element.
 */
int lomuto_partition(int *array, int lw, int hg, size_t size)
{
	int pivot = array[hg];
	int i = lw - 1;
	int j;

	for (j = lw; j < hg; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			if (i != j)
			{
				int temp = array[i];

				array[i] = array[j];
				array[j] = temp;
				print_array(array, size);
			}
		}
	}
	if (i + 1 != hg)
	{
		int temp = array[i + 1];

		array[i + 1] = array[hg];
		array[hg] = temp;
		print_array(array, size);
	}
	return (i + 1);
}
