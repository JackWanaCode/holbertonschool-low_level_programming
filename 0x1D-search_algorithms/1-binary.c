#include <stdio.h>
#include <stdlib.h>
#include "search_algos.h"

/**
 * bs_help - Entry point
 * Description: help searches for a value in a sorted array of integers
 * using the Binary search algo
 * @array: array of intergers
 * @size: size of array
 * @value: value for searching
 * @first: first for start point in array
 * @last: second for end point in array
 * Return: position of value or -1 if not found
 */

int bs_help(int *array, size_t size, int value,
		  size_t first, size_t last)
{
	size_t i;

	printf("Searching in array: ");
	for (i = first; i < last; i++)
		printf("%d, ", array[i]);
	printf("%d\n", array[i]);
	if (first == last)
	{
		if (array[first] == value)
			return (first);
		return (-1);
	}
	if (value == array[(last + first) / 2])
		return ((last + first) / 2);
	if (value < array[(last + first) / 2])
		return (bs_help(array, size, value, first,
				(last + first) / 2 - 1));
	return (bs_help(array, size, value, ((last + first) / 2) + 1,
			last));
}

/**
 * binary_search - Entry point
 * Description: searches for a value in a sorted array of integers
 * using the Binary search algo
 * @array: array of intergers
 * @size: size of array
 * @value: value for searching
 * Return: position of value or -1 if not found
 */

int binary_search(int *array, size_t size, int value)
{
	size_t first = 0;
	size_t last = size - 1;

	if (!array)
		return (-1);
	return (bs_help(array, size, value, first, last));
}
