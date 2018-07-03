#include <stdio.h>
#include "holberton.h"

/**
 * _strlen - Entry point
 * Description: return length of a string.
 * @s:  string is to be checked.
 *
 * Return: string length value
 */
int _strlen(char *s)
{
	int count = 0;

	while (*(s + count) != '\0')
		count++;
	return (count);
}
