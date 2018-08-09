#include <stdio.h>
#include <limits.h>
#include "holberton.h"

/**
 * power2 - Entry point
 * Description: calculate power of 2
 * @n: number will be powered
 * Return: nothing.
 */
unsigned int power2(int n)
{
	unsigned int result = 1;
	int i = 0;

	while (i < n)
	{
		result *= 2;
		i++;
	}
	return (result);
}

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
		count = 31;
	else
		while (max * 2 <= n)
		{
			count++;
			max *= 2;
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
		max = power2(count);
	}
}
