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
	char bits;
	int m = 1;

	bits = n & m;
	if (n == 0)
		_putchar('0');
	else if (n == 1)
		_putchar('1');
	else
	{
		print_binary(n >> 1);
		_putchar(bits + '0');
	}
}
