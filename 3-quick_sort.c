#include "sort.h"

/**
 * quick_sort - sort an array using the quick sort algorithm.
 * @array: pointer to an array
 * @size: size of @array
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size == 0)
		return;
	lomuto_partition(array, size, 0, size - 1);

}

/**
 * swap - swaps 2 elements of a given array.
 *
 * @array: point to an array
 * @size: size of the array.
 * @indx: index of postion withing the array
 * @wall: index of postion withing the array
 */
void swap(int *array, size_t size, int indx, int wall)
{
	int tmp = array[wall];

	if (indx != wall)
	{
		array[wall] = array[indx];
		array[indx] = tmp;
		print_array(array, size);
	}
}

/**
 * lomuto_partition - sort a partition of an array and if need will recursevly
 * partition the array again.
 *
 * @array: arary to be partitioned and sorted
 * @size: size of the array
 * @low_p: begin of a partition. (left side)
 * @high_p: end of a partition. (right side)
 */
void lomuto_partition(int *array, size_t size, int low_p, int high_p)
{
	int i, pivot, wall;

	if ((high_p) - low_p <= 0)
		return;
	if (high_p == 1 && array[0] < array[high_p])
		return;

	i = wall = low_p;
	pivot = high_p;
	while (i < pivot)
	{
		if (array[i] < array[pivot])
		{
			swap(array, size, i, wall);
			wall++;
		}
		i++;
	}
	swap(array, size, pivot, wall);

	if (high_p - low_p > 0)
		lomuto_partition(array, size, wall + 1, high_p);
	if (high_p - low_p > 0)
		lomuto_partition(array, size, low_p, wall - 1);
}
