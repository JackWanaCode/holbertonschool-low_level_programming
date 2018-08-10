#include <stdio.h>
#include <limits.h>
#include "holberton.h"

/**
 * print_binary - Entry point
 * Description: print binary number to the screen
 * @n: base 10 number
 * Return: nothing.
 */
void print_binary(unsigned long int n)
{
	unsigned long int max = 1;
	unsigned long int m = n;
	int count = 0;

	/* special case for unsigned long max, when max always less than n */
	if (n == ULONG_MAX)
	{
 		m = (m >> 1) + 1;
		count++;
	}

	/*find maximum max that = 2^k but less than or equal  */
	while (max << 1 <= m)
	{
		count++;
		max = max << 1;
		if (max == m)
			break;
 	}

	/* while loop to compare n and max */
	while (count >= 0)
	{
		if (m >= max && m != 0)
		{
			putchar('1');
			m = m - max;
		}
		else if (m < max || m == 0)
			putchar('0');
		count--;
		max >>= 1;
	}
}
