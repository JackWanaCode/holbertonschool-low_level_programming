#include <stdio.h>
#include "holberton.h"

/**
 * binary_to_uint - Entry point
 * Description: convert base 2 to base 10
 * @b: string of binary num
 * Return: unsigned base 10.
 */
unsigned int binary_to_uint(const char *b)
{
	unsigned int num = 0;
	unsigned int num2 = 1;
	int i, j;

	if (!b)
		return (0);
	for (i = 0; b[i] != '\0'; i++)
	{
		if (b[i] < '0' || b[i] > '1')
			return (0);
	}
	for (j = i - 1; j >= 0; j--)
	{
		if (j < i - 1)
			num2 *= 2;
		num += (b[j] - '0') * num2;
	}
	return (num);
}
