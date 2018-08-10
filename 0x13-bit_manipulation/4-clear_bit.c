#include <stdio.h>
#include <limits.h>
#include "holberton.h"


/**
 * clear_bit - Entry point
 * Description: set 0 to bit at given index
 * @n: base 2 number
 * @index: index of bit will be checked
 * Return: nothing.
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
	unsigned long int m = 1;
	unsigned long int k = *n;
	unsigned long int l = 1;
	unsigned int i = 0;

	while (i < index)
	{
		l = l << 1;
		i++;
	}
	while (1)
	{
		if (k == 0)
			break;
		k = k >> 1;
		m = m << 1;
	}
	m = m - 1;
	k = m ^ l;
	*n = *n & k;
	return (1);
}
