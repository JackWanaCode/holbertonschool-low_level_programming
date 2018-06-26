#include "holberton.h"

/**
 * print_alphabet - print the character from a to z
 * Return: nothing
 */
void print_alphabet(void)
{
	char ch;

	for (ch = 'a'; ch <= 'z'; ch++)
	{
		_putchar(ch);
	}
	_putchar('\n');
}
