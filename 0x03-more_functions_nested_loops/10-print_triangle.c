#include <stdio.h>
#include "holberton.h"

/**
 * print_triangle - Entry point
 * Description: print square of white space  # size n.
 * Follow by new line. See the pattern :)
 * 0 and negative number will be print new line.
 * @size: number of size that is requested by main.c
 * ********************
 * ** size = 4     ****
 * **        #     ****
 * **       ##     ****
 * **      ###     ****
 * **     ####     ****
 * ********************
 * Return: nothing
 */
void print_triangle(int size)
{
	int r, c;

	if (size <= 0)
		_putchar('\n');
	for (r = 0; r < size; r++) /*for create n of line */
	{
		for (c = 0; c < size; c++) /*print n of #*/
		{
			if (c < size - r - 1)
				_putchar(' ');
			else
				_putchar('#');
		}
		_putchar('\n');
	}
}
