#include <stdio.h>
#include "holberton.h"

/**
 * _isdigit - Entry point
 * Description: check number for a character.
 * @c: variable c is to be checked.
 *
 * Return: 1 for true, 0 for false.
 */
int _isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}
