#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * shell_sort - sorts an array of integers in ascending order
 * @array: array
 * @size: array size
 */
void shell_sort(int *array, size_t size)
{
	unsigned int gap, i = 0, j = 0;
	int temp;

	for (gap = size / 2; gap > 0; gap = gap / 2)
	{
		for (i = gap; i < size; i++)
		{
			temp = array[i];
			for (j = i; j >= gap && array[j - gap] > temp; j -= gap)
				array[j] = array[j - gap];

			array[j] = temp;
		}
		print_array(array, size);
	}
}
