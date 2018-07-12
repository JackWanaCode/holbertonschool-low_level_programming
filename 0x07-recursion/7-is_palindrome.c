#include <stdio.h>
#include "holberton.h"

/**
 * _checkchar - Entry point
 * Description: compare 2 chars
 * @s: character in string
 * @c: character to be checked
 * @n: 1 for true, 0 for false
 * Return: nothing
 */
void _checkchar(char *s, char c, int *n)
{
	if (*(s) != '\0')
		_checkchar((s + 1), c, n);
	else
	{
		if (*(s - 1) != c)
			*n = 0;
		else
			*n = 1;
	}
}

/**
 * is_palidrome - Entry point
 * Description: check the string is palidrome?
 * @s: string to be checked
 *
 * Return: 1 if true, or 0 for false
 */
int is_palindrome(char *s)
{
	char c = *s;
	int n;

	if (!c)
		n = 1;
	if (*(s) != '\0')
		_checkchar(s, c, &n);
	else
		is_palindrome(s + 1);
	return (n);
}
