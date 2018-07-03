#include <stdio.h>
#include "holberton.h"

/**
 * puts_half - Entry point
 * Description: print second half of string. Start from str length / 2
 * @str:  str is to be printed.
 *
 * Return: no return.
 */
void puts_half(char *str)
{
	int i;
	int length = 0;

	while (*(str + length) != '\0')
		length++;
	i = (length - 1) / 2;
	while (i < length)
	{
		_putchar(*(str + i));
		i++;
	}
	_putchar('\n');
}
