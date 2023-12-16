#include "sort.h"

/**
 * swapidx - Swaps the values of two integers.
 * @num1: Pointer to the first integer.
 * @num2: Pointer to the second integer.
 *
 * This function swaps the values of the two integers
 * by utilizing a temporary variable.
 */
void swapidx(int *num1, int *num2)
{
	int tmp;

	tmp = *num1;
	*num1 = *num2;
	*num2 = tmp;
}

/**
 * lomuto - Partitions an array based on a pivot.
 * @array: Pointer to the array.
 * @left: The left index of the current lomuto.
 * @right: The right index of the current lomuto.
 * @size: The size of the array.
 * Return: int
 */
int lomuto(int *array, int left, int right, size_t size)
{
	int *pivot, j, i;

	pivot = array + right;
	for (j = i = left; i < right; i++)
	{
		if (array[i] < *pivot)
		{
			if (j < i)
			{
				swapidx(array + i, array + j);
				print_array(array, size);
			}
			j++;
		}
	}

	if (array[j] > *pivot)
	{
		swapidx(array + j, pivot);
		print_array(array, size);
	}

	return (j);
}
/**
 * quickSort - Sorts an array using QuickSort.
 * @arr: Pointer to the array.
 * @low: The lower index of the current partition.
 * @high: The higher index of the current partition.
 * @size: The size of the array.
 */
void quickSort(int *arr, int low, int high, size_t size)
{
	if (low < high)
	{
		int pi = lomuto(arr, low, high, size);

		quickSort(arr, low, pi - 1, size);
		quickSort(arr, pi + 1, high, size);
	}
}
/**
 * quick_sort - Sorts an array using QuickSort.
 * @array: Pointer to the array.
 * @size: The size of the array.
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size <= 1)
		return;
	quickSort(array, 0, size - 1, size);
}
