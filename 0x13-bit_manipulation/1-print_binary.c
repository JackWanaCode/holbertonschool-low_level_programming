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
	int count = 0;

	/* find maximum max that = 2^k but less than or equal n */
	if (n == ULONG_MAX)
		count = 32;
	else
		while (max << 1 <= n)
		{
			count++;
			max <<= 1;
		}

	/* while loop to compare n and max */
	while (count >= 0)
	{
		if (n >= max && n != 0)
		{
			putchar('1');
			n = n - max;
		}
		else if (n < max || n == 0)
			putchar('0');
		count--;
		max >>= 1;
	}
}
