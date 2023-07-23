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
 * selection_sort - sortin algorithm using selection
 * @array: the array to be sorted
 * @size: the number of elements in the array
 */

void selection_sort(int *array, size_t size)
{
	size_t i, count, num, changer = 0;

	for (i = 0; i < size - 1; i++)
	{
		count = i + 1;
		num = i;
		while (count < size)
		{
			if (array[num] > array[count])
			{
				num = count;
				changer = 1;
			}
			count++;
		}
		if (changer)
		{
			swap(array, i, num);
			changer = 0;
			print_array(array, size);
		}
	}
}
