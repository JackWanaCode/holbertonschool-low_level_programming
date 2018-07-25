#include <stdio.h>
#include <stdlib.h>
#include "function_pointers.h"

/**
 * int_index - Entry point
 * Description: searching matched integer in array.
 * @array: array of integer
 * @size: size of array
 * @cmp: function pointer to another function.
 *
 * Return: return index of the first element which matches
 */
int int_index(int *array, int size, int (*cmp)(int))
{
	int i;

	for (i = 0; i < size; i++)
	{
		if ((*cmp)(array[i]))
			return (i);
	}
	return (-1);
}
