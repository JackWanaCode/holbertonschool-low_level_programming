#include <stdio.h>
#include <limits.h>
#include "holberton.h"


/**
 * flip_bits - Entry point
 * Description: check how many bits to flib that makes n to be m
 * @n: first num
 * @m: second num
 * Return: unsigned int num.
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned int count = 0;

	if (n == 0 && m == 0)
		return (0);
	/* masking to get the last number */
	else if ((n & 1) != (m & 1))
		count = 1 + flip_bits(n >> 1, m >> 1);
	else
		count = flip_bits(n >> 1, m >> 1);
	return (count);
}
