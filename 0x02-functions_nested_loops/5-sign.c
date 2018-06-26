#include "holberton.h"

/**
 * print_sign - check numbern is positive, negative or zero?
 * @n: the character to be checked
 *
 * Return: 1 if lowercase or uppercase letter and 0 otherwise
 */
int print_sign(int n)
{
	if (n > 0)
	{
		_putchar('+');
		return (1);
	}
	else if (n < 0)
	{
		_putchar('-');
		return (-1);
	}
	else
	{
		_putchar(n + '0');
		return (0);
	}
}
