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
	if (sizeof(unsigned long int) * 8 < index)
		return (-1);
	return ((n >> index) % 2);
}
