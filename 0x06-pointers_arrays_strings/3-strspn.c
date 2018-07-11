#include <stdio.h>
#include "holberton.h"

/**
 * _strspn - Entry point
 * Description: return max index + 1 that stored a given string.
 * @s: bigger string.
 * @accept: given string
 *
 * Return: index
 */
unsigned int _strspn(char *s, char *accept)
{
	int i, j;

	for (i = 0; *(s + i) != '\0'; i++)
	{
		for (j = 0; *(accept + j) != '\0'; j++)
		{
			if (*(s + i) == *(accept + j))
			{
				break;
			}
		}
		if (*(accept + j) == '\0')
			break;
	}
	return (i);
}
