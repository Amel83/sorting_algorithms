#include <stdio.h>
#include "sort.h"

/**
 * bubble_sort - Bubble sort.
 * @array: Pointer.
 * @size: Size of the array.
 */
void bubble_sort(int *array, size_t size)
{
	int temp;
	int flag;
	size_t i, j;

	if (array == NULL || size < 2)
		return;
	for (i = 0; i < size - 1; i++)
	{
		flag = 0;
		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				flag = 1;
				print_array(array, size);
			}
		}
		if (flag == 0)
			break;
	}
}
