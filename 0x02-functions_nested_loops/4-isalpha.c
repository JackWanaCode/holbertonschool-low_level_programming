#include "holberton.h"

/**
 * _isalpha - check the c is letter?
 * @c: the character to be checked
 *
 * Return: 1 if lowercase or uppercase letter and 0 otherwise
 */
int _isalpha(int c)
{
	if (c >= 97 && c <= 122)
		return (1);
	else if (c >= 65 && c <= 90)
		return (1);
	else
		return (0);
}
