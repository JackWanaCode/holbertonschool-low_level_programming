#include <stdio.h>
#include "holberton.h"

/**
 * print_diagonal - Entry point
 * Description: print n rows of n-1 ' ', ended by \ on screen,
 * followed by new line. See the pattern :)
 * 0 and negative number will be print new line.
 * @n: number of line that is requested by main.c
 * ************************
 * **** n = 4    **********
 * ****          **********
 * **** \        **********
 * ****  \       **********
 * ****   \      **********
 * ****    \     **********
 * ************************
 * Return: nothing
 */
void print_diagonal(int n)
{
	int i, j;

	if (n <= 0)
		_putchar('\n');
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < i; j++)
		{
			_putchar(' ');
		}
		_putchar('\\');
		_putchar('\n');
	}
}
