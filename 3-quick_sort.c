#include "sort.h"

/**
 * swaper - fro swapping values
 * @array: the given array
 * @size: size of the given array
 * @low: left val
 * @high: right val
 */

void swaper(int *array, size_t size, int low, int high)
{
	int temporary;

	if (array[low] != array[high])
	{
		temporary = array[low];
		array[low] = array[high];
		array[high] = temporary;
		print_array(array, size);
	}
}

/**
 * parti - partistion schemem for quik sort
 * @array: the gievn array
 * @size: size of the given array
 * @low: left val
 * @high: right val
 * Return: value of the pivot
 */

int parti(int *array, size_t size, int low, int high)
{
	int pivotval = array[high];

	int i = low - 1, j;

	for (j = low; j <= high; j++)
	{
		if (array[j] < pivotval)
		{
			i++;
			swaper(array, size, i, j);
		}
	}
	swaper(array, size, i + 1, high);
	return (i + 1);
}

/**
 * recursion - the recursive function
 * @array: the gien array
 * @size: size of the given array
 * @low: low val
 * @high: high val
 */
void recursion(int *array, size_t size, int low, int high)
{
	int pivotindex;

	if (low < high)
	{
		pivotindex = parti(array, size, low, high);
		recursion(array, size, low, pivotindex - 1);
		recursion(array, size, pivotindex + 1, high);
	}
}
/**
 * quick_sort - the quick sort algorithm
 * @array: array to be sorted
 * @size: size of the given array
 */

void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	recursion(array, size, 0, size - 1);
}
