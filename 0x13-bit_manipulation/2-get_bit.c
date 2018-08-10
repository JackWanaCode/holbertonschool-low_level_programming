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
		if (n == 0)
                        break;
		n = n >> 1;
		i++;
	}
	if (i == index)
		return (n % 2);
	else
		return (-1);
}
