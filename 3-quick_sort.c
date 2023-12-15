#include "sort.h"
/**
 * swap - Swaps two integer values.
 * @num1: Pointer to the first integer.
 * @num2: Pointer to the second integer.
 */

void swap(int *num1, int *num2)
{
	int tmp;

	tmp = *num1;
	*num1 = *num2;
	*num2 = tmp;
}
/**
 * lumoto - Implements the Lomuto partition scheme for Quick sort.
 * @array: Pointer to the array to be sorted.
 * @low: Index of the first element of the partition to be sorted.
 * @high: Index of the last element of the partition to be sorted.
 * @size: Size of the array.
 */

void lumoto(int *array, size_t low, size_t high, size_t size)
{

	int pivot = array[high];
	size_t i = low, j = low;

	if (low >= high)
		return;

	for (; i < high; i++)
	{
		if (array[i] <= pivot)
		{
			swap(&array[i], &array[j]);
			j++;
		}
	}

	swap(&array[j], &array[high]);
	print_array(array, size);

	if (j > 0)
		lumoto(array, low, j - 1, size);

	lumoto(array, j + 1, high, size);
}

/**
 * quick_sort - Sorts an array of integers
 * in ascending order using Quick sort.
 * @array: Pointer to the array to be sorted.
 * @size: Size of the array.
 */
void quick_sort(int *array, size_t size)
{
	lumoto(array, 0, size - 1, size);
	print_array(array, size);
}
