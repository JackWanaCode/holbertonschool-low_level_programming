#include "holberton.h"

/**
 * print_number - Entry point
 * Description: putchar any kind of integer
 * @n: number to be print
 * Return: Nothing
 */
void print_number(int n)
{
	int temp1, temp2;
	int num;
	int spcase = 0;

	if (n < 0 && n > -2147483648)
	{
		_putchar('-');
		n = n * -1;
	}
	else if (n == -2147483648)
	{
		_putchar('-');
		spcase = (n % 10) * -1;
		n = n / -10;
	}
	num = n;
	temp1 = n / 10;
	temp2 = 10;
	while (temp1 / 10)
	{
		temp1 = temp1 / 10;
		temp2 = temp2 * 10;
	}
	while (temp2 > 1 && num > 9)
	{
		_putchar(n / temp2 + '0');
		n = n % temp2;
		temp2 = temp2 / 10;
	}
	_putchar(n % 10 + '0');
	if (spcase)
		_putchar(spcase + '0');
}
