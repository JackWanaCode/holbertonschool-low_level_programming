#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

void shell(int *array, size_t reach, size_t size);


/**
 * shell_sort - sorts array with shell sort
 * @array: array of integers
 * @size: size of array
 */

void shell_sort(int *array, size_t size)
{
	size_t test = 0, reach;

	while (test < size)
		test = (test * 3) + 1;
	reach = (test - 1) / 3;
	shell(array, reach, size);
}

/**
 * shell - shell sort helper
 * @array: array
 * @reach: increment
 * @size: size of array
 */

void shell(int *array, size_t reach, size_t size)
{
	size_t lo = 0, next = (reach - 1) / 3, inc = reach;
	int temp;

	while (reach < size)
	{
		if (array[lo] > array[reach])
		{
			temp = array[reach];
			array[reach] = array[lo];
			array[lo] = temp;
			reach = inc;
			lo = 0;
		}
		reach++;
		lo++;
	}
	print_array(array, size);
	if (next > 0)
		shell(array, next, size);
