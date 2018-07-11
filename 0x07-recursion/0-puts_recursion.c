#include <stdio.h>
#include "holberton.h"

/**
 * _puts_recursion - Entry point
 * Description: use recursion to print the string
 * @s: string that need to be printed
 *
 * Return: nothing
 */
void _puts_recursion(char *s)
{
	if (*(s) != '\0')
	{
		_putchar(*s);
		_puts_recursion(s + 1);
	}
	else
	{
		_putchar('\n');
	}
}
