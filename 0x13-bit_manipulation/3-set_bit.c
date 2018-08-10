#include <stdio.h>
#include <limits.h>
#include "holberton.h"


/**
 * set_bit - Entry point
 * Description: set 1 to bit at given index
 * @n: base 2 number
 * @index: index of bit will be checked
 * Return: nothing.
 */
int set_bit(unsigned long int *n, unsigned int index)
{
	unsigned long int m = 1;
	unsigned int i = 0;

	while (i < index)
	{
		m = m << 1;
		i++;
	}
	*n = *n | m;
	return (1);
}
