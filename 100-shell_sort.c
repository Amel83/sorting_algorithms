#include <stdio.h>
#include "sort.h"

/**
 * shell_sort - Sorts in shell.
 * @array: Pointer to the array.
 * @size: Size.
 */

void shell_sort(int *array, size_t size)
{
	size_t gap, i, k;
	int j;

	if (array == NULL || size < 2)
		return;
	gap = 1;
	while (gap < size / 3)
		gap = gap * 3 + 1;
	while (gap > 0)
	{
		for (i = gap; i < size; i++)
		{
			j = array[i];
			k = i;
			while (k >= gap && array[k - gap] > j)
			{
				array[k] = array[k - gap];
				k -= gap;
			}
			array[k] = j;
		}
		print_array(array, size);
		gap = (gap - 1) / 3;
	}
}
