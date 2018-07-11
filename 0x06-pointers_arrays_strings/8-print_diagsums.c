#include <stdio.h>
#include "holberton.h"

/**
 * print_diagsums - Entry point
 * Description: sum of the two diagonals of a square matrix of integers.
 * @a: a pointer point to an 2d array
 * @size: size of 2d array
 * Return: no thing.
 */
void print_diagsums(int *a, int size)
{
	int i;
	int ret1 = 0;
	int ret2 = 0;

	for (i = 0; i < (size * size); i = i + size + 1)
	{
		ret1 += *(a + i);
	}
	for (i = size - 1; i < (size * size - (size - 1)); i = i + size - 1)
	{
		ret2 += *(a + i);
	}
	printf("%i, %i\n", ret1, ret2);
}
