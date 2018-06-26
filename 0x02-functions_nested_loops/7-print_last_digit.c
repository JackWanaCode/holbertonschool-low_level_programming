#include "holberton.h"

/**
 * _print_last_digit - check number and return absolute value
 * @n: the number to be checked
 *
 * Return: return absolut number
 */
int print_last_digit(int n)
{
	int last_digit;

	last_digit = n % 10;
	if (last_digit >= 0)
	{
		_putchar(last_digit + '0');
		return (last_digit);
	}
	else
	{
		_putchar((last_digit * -1) + '0');
		return (last_digit * -1);
	}
}
