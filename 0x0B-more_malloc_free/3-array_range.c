#include <stdio.h>
#include <stdlib.h>
#include "holberton.h"

/**
 * array_range - Entry Point
 * Description: return a array of interger from min to max
 * @min: minimum number.
 * @max: maximum number
 * Return: nothing
 */
int *array_range(int min, int max)
{
	int *arr;
	int n, i = 0;

	if (min > max)
		return (NULL);
	n = max - min;
	arr = malloc(sizeof(int) * (n + 1));
	if (arr == NULL)
		return (NULL);
	while (min <= max)
		arr[i++] = min++;
	return (arr);
}
