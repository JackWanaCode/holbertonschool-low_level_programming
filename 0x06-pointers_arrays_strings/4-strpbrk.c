#include <stdio.h>
#include "holberton.h"

/**
 * _strpbrk - Entry point
 * Description: return pointer to the byte
 * @s: bigger string.
 * @accept: given string
 *
 * Return: pointer to 1st occurence
 */
char *_strpbrk(char *s, char *accept)
{
	int i, j;

	for (i = 0; *(s + i) != '\0'; i++)
	{
		for (j = 0; *(accept + j) != '\0'; j++)
		{
			if (*(s + i) == *(accept + j))
				return (s + i);
		}
	}
	return (NULL);
}
