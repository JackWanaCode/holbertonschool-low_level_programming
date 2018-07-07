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
	int digit = 1;
	int last_num = n % 10;
	int tmp_num;

	n = n / 10;
	if (n < 0)
	{
		last_num *= -1;
		_putchar('-');
		n *= -1;
	}
	tmp_num = n;
	while (tmp_num > 0)
	{
		digit *= 10;
		tmp_num /= 10;
	}
	digit /= 10;
	while (digit > 0)
	{
		_putchar (n / digit + '0');
		n = n % digit;
		digit /= 10;
	}
	_putchar(last_num + '0');
}
