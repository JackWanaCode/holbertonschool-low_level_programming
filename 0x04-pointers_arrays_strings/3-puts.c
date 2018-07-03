#include <stdio.h>
#include "holberton.h"

/**
 * _puts - Entry point
 * Description: prints a string.
 * @str:  str is to be printed.
 *
 * Return: no return.
 */
void _puts(char *str)
{
	int i;

	for (i = 0; *(str + i) != '\0'; i++)
	{
		_putchar(*(str + i));
	}
	_putchar('\n');
}
