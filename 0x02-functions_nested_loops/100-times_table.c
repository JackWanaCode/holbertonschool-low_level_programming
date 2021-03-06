#include "holberton.h"

/**
 * print_times_table - print table of n times
 * @n: number to be checked
 *
 */
void print_times_table(int n)
{
	int i = 0;
	int j, k;

	while (n >= 0 && n < 15 && i <= n)
	{
		for (j = 0; j <= n; j++)
		{
			k = i * j;
			if (j == 0)
			{
				_putchar('0');
			}
			else if (k < 10)
			{
				_putchar(',');
				_putchar(' ');
				_putchar(' ');
				_putchar(' ');
				_putchar(k + '0');
			}
			else if (k < 100)
			{
				_putchar(',');
				_putchar(' ');
				_putchar(' ');
				_putchar((k / 10) + '0');
				_putchar((k % 10) + '0');
			}
			else
			{
				_putchar(',');
				_putchar(' ');
				_putchar((k / 100) + '0');
				_putchar(((k % 100) / 10) + '0');
				_putchar((k % 10) + '0');
			}
		}
		i++;
		_putchar('\n');
	}
}
