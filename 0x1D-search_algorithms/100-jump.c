#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "search_algos.h"

/**
 * linear_s - Entry point
 * Description: searches for a value in an array of integers
 * using the Linear search algo
 * @array: array of intergers
 * @size: size of array
 * @step: step of jump
 * @value: value for searching
 * @position: position of index
 * Return: postion of value or -1 if not found
 */

int linear_s(int *array, size_t size, size_t step, int value, int position)
{
	size_t i, j;

	for (i = position, j = 0; i < size && j < step; i++, j++)
	{
		printf("Value checked array[%lu] = [%d]\n",
		       i, array[i]);
		if (array[i] == value)
			return (i);
	}
	return (-1);
}

/**
 * jump_search - Entry point
 * Description: searches for a value in a sorted array of integers
 * using the Jump search algo
 * @array: array of intergers
 * @size: size of array
 * @value: value for searching
 * Return: position of value or -1 if not found
 */

int jump_search(int *array, size_t size, int value)
{
	size_t step = sqrt(size);
	size_t i;

	if (!array || size == 0)
		return (-1);
	for (i = 0; i < size + step; i += step)
	{
		if (array[i] >= value || i >= size)
		{
			if (i != 0)
				i -= step;
			printf("Value found between indexes [%lu] and [%lu]\n",
			       i, i + step);
			return (linear_s(array, size, step + 1, value, i));
		}
		printf("Value checked array[%lu] = [%d]\n", i, array[i]);
	}
	return (-1);
}
