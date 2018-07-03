#include <stdio.h>
#include "holberton.h"

/**
 * print_array - Entry point
 * Description: print n element of an array of integers
 * @a:  array of integers.
 * @n: number of element will be printed
 *
 * Return: no return.
 */
void print_array(int *a, int n)
{
	int i;

	for (i = 0; i < n; i++)
	{
		printf("%i", *(a + i));
		if (i < n - 1)
		{
			printf(", ");
		}
	}
	printf("\n");
}
