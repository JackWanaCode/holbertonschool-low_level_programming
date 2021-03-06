#include <stdio.h>
#include "holberton.h"

/**
 * _strchr - Entry point
 * Description: return a pointer to the first occurrence of the character c.
 * @s: string that will be iterate to check.
 * @c: character will be check with s. If it doesn't match, return 0.
 *
 * Return: pointer to pointer.
 */
char *_strchr(char *s, char c)
{
	unsigned int i;

	for (i = 0; *(s + i) != '\0'; i++)
		if (*(s + i) == c)
			return (s + i);
	if (c == '\0')
		return (s + i);
	return (NULL);
}
