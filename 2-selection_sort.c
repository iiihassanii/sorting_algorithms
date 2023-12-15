#include "sort.h"


void selection_sort(int *array, size_t size)
{
	size_t i, j, smallest;
	int tmp;

	if (array == NULL)
		return;

	for (i = 0; i < size - 1; i++)
	{
		smallest = i;

		for (j = i + 1; j < size; j++)
			if (array[j] < array[smallest])
				smallest = j;
		
		if (smallest != i)
		{
			tmp = array[i];
			array[i] = array[smallest];
			array[smallest] = tmp;
			print_array(array, size);
		}
	}
}
