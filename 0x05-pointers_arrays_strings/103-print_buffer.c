#include <stdio.h>
#include <ctype.h>
#include "holberton.h"

/**
 * print_buffer - Entry point
 * Description: print the buffer follow the format.
 * @b: source of buffer.
 * @size: size of buffer.
 *
 * Return: nothing
 */
void print_buffer(char *b, int size)
{
	int i = 0;
	int tmp, count;

	while (i < size)
	{
		printf("%08x: ", i);
		count = 0;
		tmp = i;
		while (count < 5)
		{
			if (i >= size)
				printf("     ");
			else
			{
				printf("%02x", *(b + i++));
				printf("%02x ", *(b + i++));
			}
			count++;
		}
		i = tmp;
		count = 0;
		while (count < 10 && i < size)
		{
			if (isprint(*(b + i)))
				putchar(*(b + i));
			else
				putchar('.');
			count++;
			i++;
		}
		putchar('\n');
	}
}
