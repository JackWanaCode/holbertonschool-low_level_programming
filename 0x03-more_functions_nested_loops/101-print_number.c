#include "holberton.h"

/**
 * print_number - Entry point
 * Description: putchar any kind of integer
 * @n: number to be print
 * Return: Nothing
 */
void print_number(int n)
{
	int temp1 = n / 10;
	int temp2 = 10;
	int num;

	if (n < 0)
	{
		_putchar('-');
		n *= -1;
	}
	num = n;
	while (temp1 / 10)
	{
		temp1 /= 10;
		temp2 *= 10;
	}
	while (temp2 > 1 && num > 9)
	{
		_putchar(n / temp2 + '0');
		n = n % temp2;
		temp2 /= 10;
	}
	_putchar(n % 10 + '0');
}
