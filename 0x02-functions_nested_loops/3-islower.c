#include "holberton.h"

/**
 * _islower - check the c is lowercase?
 * @c: the character to be checked
 *
 * Return: 1 if lowercase and 0 other wise
 */
int _islower(int c)
{
	if (c >= 97 && c <= 122)
		return (1);
	else
		return (0);
}
