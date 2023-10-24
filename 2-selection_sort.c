#include "sort.h"

/**
 * selection_sort - a function that sorts an array of integers
 * in ascending order using the Selection sort algorithm.
 * @array: the array to be considered.
 * @size: the size of the array.
 *
 * Return: Nothing
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, minIndex;
	int tmp;

	if (size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		minIndex = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[minIndex])
				minIndex = j;
		}
		tmp = array[i];
		array[i] = array[minIndex];
		array[minIndex] = tmp;
		print_array(array, size);
	}
}
