#include <stdio.h>
#include <limits.h>
#include "holberton.h"


/**
 * get_bit - Entry point
 * Description: print value of bit at index
 * @n: base 2 number
 * @index: index of bit will be checked
 * Return: nothing.
 */
int get_bit(unsigned long int n, unsigned int index)
{
	unsigned int i = 0;

	while (i < index)
	{
		n = n >> 1;
		i++;
		if (n == 0)
			break;
	}
	if (i > index)
		return (-1);
	return (n % 2);
}
