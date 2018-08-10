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
	unsigned long int n1, n2;
	unsigned long int m1, m2;
	unsigned int count = 0;

	while (1)
	{
		if (n == 0 && m == 0)
			break;
		n1 = n >> 1;
		n2 = n1 << 1;
		m1 = m >> 1;
		m2 = m1 << 1;
		if (n - n2 != m - m2)
			count++;
		n = n >> 1;
		m = m >> 1;
	}
	return (count);
}
