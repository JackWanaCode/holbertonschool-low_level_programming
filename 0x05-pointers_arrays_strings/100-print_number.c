#include "holberton.h"

/**
 * print_number - Entry point
 * Description: print number by putchar
 * @n: number is to be printed
 *
 * Return: nothing
 */
void print_number(int n)
{
	if (n <= 9 && n >= 0)
	{
		_putchar(n + '0');
	}
	else if (n >= -9 && n <= -1)
	{
		n = n * -1;
		_putchar('-');
		_putchar(n + '0');
	}
	else
	{
		print_number(n / 10);
		n = n % 10;
		if (n < 0)
			n *= -1;
		_putchar(n + '0');
	}
}
