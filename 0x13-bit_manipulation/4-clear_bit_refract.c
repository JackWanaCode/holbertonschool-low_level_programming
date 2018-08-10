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

	if (sizeof(unsigned long int) * 8 < index)
		return (-1);
	m = m << index;
	m = ~m;
	*n = *n & m;
	return (1);
}
