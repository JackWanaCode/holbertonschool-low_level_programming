#include <stdio.h>
#include "holberton.h"

/**
 * print_line - Entry point
 * Description: print n of '_' on screen, followed by new line.
 * 0 and negative number will be print new line.
 * @n: number of '_' is requested by main.c
 * Return: nothing
 */
void print_line(int n)
{
	int i;

	for (i = 0; i < n; i++)
	{
		_putchar('_');
	}
	_putchar('\n');
}
