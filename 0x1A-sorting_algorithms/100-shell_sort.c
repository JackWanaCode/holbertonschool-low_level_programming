#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * insertion_help - help to sort data by insertion
 *
 * @array: Array to convert to a doubly linked list
 * @size: Size of the array
 * @f_point: first point of array will be sorted
 * @interval: interval will for a virtual sub array
 * Return:
 */

void insertion_help(int *array, size_t size, size_t f_point, size_t interval)
{
	size_t i = f_point + interval;
	size_t j;
	int temp;

	for (; i < size; i += interval)
	{
		temp = array[i];
		j = i;
		for (; temp < array[j - interval] && j > f_point; j -= interval)
		{
			array[j] = array[j - interval];

		}
		array[j] = temp;
	}
}

/**
 * shell_sort_help -  help function to sort data by shell_sort
 *
 * @array: Array to convert to a doubly linked list
 * @size: Size of the array
 * @interval: interval will for a virtual sub array
 * Return:
 */

void shell_sort_help(int *array, size_t size, size_t interval)
{
	size_t i = 0;

	for (; i < interval; i++)
	{
		insertion_help(array, size, i, interval);
	}
}


/**
 * shell_sort - sort data by shell_sort
 *
 * @array: Array to convert to a doubly linked list
 * @size: Size of the array
 *
 * Return:
 */

void shell_sort(int *array, size_t size)
{
	size_t interval = 0;

	if (!array || size < 2)
		return;
	for (; interval < size; interval = interval * 3 + 1)
		;
	interval = (interval - 1) / 3;
	for (; interval > 0;)
	{
		shell_sort_help(array, size, interval);
		print_array(array, size);
		interval = (interval - 1) / 3;
	}
}
