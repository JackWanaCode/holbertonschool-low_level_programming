#include <stdio.h>
#include "holberton.h"

/**
 * string_toupper - Entry point
 * Description: upcase on character.
 * @s: string to be upcase
 *
 * Return: nothing
 */
char *string_toupper(char *s)
{
	int i;

	for (i = 0; *(s + i) != '\0'; i++)
	{
		if (*(s + i) >= 97 && *(s + i) <= 122)
			*(s + i) = *(s + i) - 32;
	}
	return (s);
}
