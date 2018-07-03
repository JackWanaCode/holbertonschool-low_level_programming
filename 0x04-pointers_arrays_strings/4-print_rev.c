#include <stdio.h>
#include "holberton.h"

/**
 * print_rev - Entry point
 * Description: print a string, in reverse. follow by new line
 * @s:  string is to be checked.
 *
 * Return: string length value
 */
void print_rev(char *s)
{
	int length = 0;

	while (*(s + length) != '\0')
		length++;
	length--;
	while (length >= 0)
	{
		_putchar(*(s + length));
		length--;
	}
	_putchar('\n');
}
