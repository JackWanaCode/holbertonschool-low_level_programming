#include <stdio.h>
#include "holberton.h"

/**
 * reverse_array - Entry point
 * Description: reverse element in an array.
 * @a: array will be reversed
 * @n: size of array
 *
 * Return: nothing
 */
void reverse_array(int *a, int n)
{
	int i, tmp;
	int l = n - 1;

	for (i = 0; i < n / 2; i++, l--)
	{
		tmp = a[i];
		a[i] = a[l];
		a[l] = tmp;
	}
}
