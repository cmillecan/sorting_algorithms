#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * quick_sort -  sorts an array of integers in ascending order
 * @array: array
 * @size: array size
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	quick_swap(array, 0, size - 1, size);	
}
/**
 * quick_swap - sorts an array of integers
 * @array: first element
 * @low: lowest int
 * @high: highest int
 * @size: array size
 */
void quick_swap(int *array, int low, int high, size_t size)
{
	int p_index;

	if (low < high)
	{
		p_index = partition(array, low, high, size);

		quick_swap(array, low, p_index - 1, size);
		quick_swap(array, p_index + 1, high, size);
	}	
}
/**
 * partition - takes the last element as a pivot to sort array
 * @array: array
 * @low: lowest int
 * @high: highest int
 * @size: array size
 */
int partition(int *array, int low, int high, size_t size)
{
	int pivot, i, j;

	pivot = array[high];
	i = (low - 1);

	for (j = low; j <= high - 1; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			swap(&array[i], &array[j]);
		}
	}
	swap(&array[i + 1], &array[high]);
	print_array(array, size);

	return (i + 1);
}
/**
 * swap - swaps two elements
 * @a: first element
 * @b: second element
 * @array: array
 */
void swap(int *a, int * b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}
