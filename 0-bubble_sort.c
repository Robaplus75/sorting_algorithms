#include "sort.h"

/**
 * swap - swaps two elements
 * @arr: the array to be swapped
 * @i1: index 1
 * @i2: index 2
 */

void swap(int *arr, int i1, int i2)
{
	int temp = arr[i1];

	arr[i1] = arr[i2];
	arr[i2] = temp;
}

/**
 * bubble_sort - sorts an array of number in order
 * @array: the array to be sorted
 * @size: the number of elements in the array
 */

void bubble_sort(int *array, size_t size)
{
	int check = 1;
	size_t i, j;

	if (array == NULL || size == 0)
		return;

	for (j = 0; j < (size - 1); j++)
	{
		check = 0;
		for (i = 0; i < (size - 1); i++)
		{
			if (array[i] > array[i + 1])
			{
				swap(array, i, i + 1);
				print_array(array, size);
				check = 1;
			}

		}
		if (check == 0)
		{
			break;
		}
	}
}
