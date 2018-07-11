#include <stdio.h>
#include "holberton.h"

/**
 * _strlen_recursion - Entry point
 * Description: use recursion to return length of string
 * @s: string that need to be printed
 *
 * Return: length of s
 */
int _strlen_recursion(char *s)
{
	int n = 1;

	if (*(s) == '\0')
	{
		return (0);
	}
	else
	{
		n = n + _strlen_recursion(s + 1);
		return (n);
	}
}
