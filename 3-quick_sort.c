#include <stdio.h>
#include "sort.h"

/**
 * quick_sort - Sorts an array of integers in ascending order
 *              using the Quick sort algorithm with Lomuto partition.
 * @array: Pointer to the array to be sorted.
 * @size: Size of the array.
 */
void quick_sort(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    quick_sort_recursive(array, 0, size - 1);
}

/**
 * quick_sort_recursive - Helper function for Quick sort.
 * @array: Pointer to the array to be sorted.
 * @low: Starting index of the partition to be sorted.
 * @high: Ending index of the partition to be sorted.
 */
void quick_sort_recursive(int *array, int low, int high)
{
    if (low < high)
    {
        int partition_idx = lomuto_partition(array, low, high);
        quick_sort_recursive(array, low, partition_idx - 1);
        quick_sort_recursive(array, partition_idx + 1, high);
    }
}

/**
 * lomuto_partition - Lomuto partition scheme for Quick sort.
 * @array: Pointer to the array to be partitioned.
 * @low: Starting index of the partition to be sorted.
 * @high: Ending index of the partition to be sorted.
 * Return: Index of the pivot element after partition.
 */
int lomuto_partition(int *array, int low, int high)
{
    int pivot = array[high];
    int i = low - 1;
    int j;

    for (j = low; j < high; j++)
    {
        if (array[j] <= pivot)
        {
            i++;
            if (i != j)
            {
                int temp = array[i];
                array[i] = array[j];
                array[j] = temp;
                print_array(array, high + 1);
            }
        }
    }

    if (i + 1 != high)
    {
        int temp = array[i + 1];
        array[i + 1] = array[high];
        array[high] = temp;
        print_array(array, high + 1);
    }

    return (i + 1);
}
