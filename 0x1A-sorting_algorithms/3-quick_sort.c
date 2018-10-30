#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * partition - find a partition
 *
 * @array: Array
 * @f_p: first point of array
 * @s_p: second point of array
 * @f_size: full size for printing
 * Return: partition index
 */

size_t partition(int *array, size_t f_p, size_t s_p, size_t f_size)
{
	size_t j = f_p;
	size_t i = 0;
	int temp;
	int x = array[s_p];

	i = f_p;
	for (; j < s_p; j++)
	{
		if (array[j] <= x)
		{
			if (i != j)
			{
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
				print_array(array, f_size);
			}
			i = i + 1;
		}
	}
	if (j != f_p && i != s_p)
	{
		temp = array[i];
		array[i] = array[s_p];
		array[s_p] = temp;
		print_array(array, f_size);
	}
	return (i);
}

/**
 * quick_sort_help - sort data by quicksort algorithm
 *
 * @array: Array
 * @f_p: first point of array
 * @s_p: second point of array
* @f_size: full size for printing
 * Return:
 */

void quick_sort_help(int *array, size_t f_p, size_t s_p, size_t f_size)
{
	size_t p;

	p = partition(array, f_p, s_p, f_size);
	if (p - f_p > 1)
		quick_sort_help(array, f_p, (p - 1), f_size);
	if (s_p - p > 1)
		quick_sort_help(array, (p + 1), s_p, f_size);
}

/**
 * quick_sort - sort data by quicksort algorithm
 *
 * @array: Array
 * @size: Size of the array
 *
 * Return:
 */

void quick_sort(int *array, size_t size)
{
	size_t f_p = 0;
	size_t s_p = size - 1;

	if (!array)
		return;
	quick_sort_help(array, f_p, s_p, size);
}
