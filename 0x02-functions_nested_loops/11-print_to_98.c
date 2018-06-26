#include <stdio.h>
#include "holberton.h"

/**
 * print_to_98 - print from n to 98 and separated by "' "
 * @n: the number to be compared with 98
 */
void print_to_98(int n)
{
	if (n <= 98)
	{
		while (n <= 98)
		{
			printf("%i", n);
			if (n < 98)
			{
				putchar(',');
				putchar(' ');
			}
			n++;
		}
	}
	else
	{
		while (n >= 98)
		{
			printf("%i", n);
			if (n > 98)
			{
				putchar(',');
				putchar(' ');
			}
			n--;
		}
	}
	putchar('\n');
}
