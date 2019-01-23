#include <stdio.h>
#include <stdlib.h>
#include "search_algos.h"

/**
 * interpolation_search - Entry point
 * Description: searches for a value in an array of integers
 * using the Linear search algo
 * @array: array of intergers
 * @size: size of array
 * @value: value for searching
 * Return: postion of value or -1 if not found
 */

int interpolation_search(int *array, size_t size, int value)
{
	size_t lo = 0, hi = size - 1, position = 0;

	if (!array)
		return (-1);
	while (lo <= hi && value >= array[lo] && value <= array[hi])
	{
		if (lo == hi)
		{
			if (array[lo] == value)
				return (lo);
			return (-1);
		}
		position = lo + (((double)(hi - lo) / (array[hi] - array[lo])) *
				 (value - array[lo]));
		printf("Value checked array[%lu] = [%d]\n",
		       position, array[position]);
		if (array[position] == value)
			return (position);
		if (array[position] < value)
			lo = position + 1;
		else
			hi = position - 1;
	}
	return (-1);
}
