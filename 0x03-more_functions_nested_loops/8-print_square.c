#include <stdio.h>
#include "holberton.h"

/**
 * print_square - Entry point
 * Description: print square of # size n. followed by new line
 * 0 and negative number will be print new line.
 * @size: number of size that is requested by main.c
 *
 * Return: nothing
 */
void print_square(int size)
{
	int i, j;

	if (size <= 0)
		_putchar('\n');
	for (i = 0; i < size; i++) /*for create n of line */
	{
		for (j = 0; j < size; j++) /*print n of #*/
		{
			_putchar('#');
		}
		_putchar('\n');
	}
}
