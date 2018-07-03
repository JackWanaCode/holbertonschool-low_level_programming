#include <stdio.h>
#include "holberton.h"

/**
 * puts2 - Entry point
 * Description: prints other character of string.
 * @str:  str is to be printed.
 *
 * Return: no return.
 */
void puts2(char *str)
{
	int i;

	for (i = 0; *(str + i) != '\0'; i++)
	{
		if (i % 2 == 0)
			_putchar(*(str + i));
	}
	_putchar('\n');
}
