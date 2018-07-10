#include <stdio.h>
#include "holberton.h"

/**
 * _strspn - Entry point
 * Description: return max index + 1 that stored a given string.
 * @s: bigger string.
 * @accept: given string
 *
 * Return: max index + 1
 */
unsigned int _strspn(char *s, char *accept)
{
	int i, j;
	int max = 0;

	for (i = 0; *(accept + i) != '\0'; i++)
	{
		for (j = 0; *(s + j) != '\0'; j++)
		{
			if (*(s + j) == *(accept + i))
			{
				if (max < j)
					max = j;
				break;
			}
		}
		if (*(s + j) == '\0')
			return (0);
	}
	return (max + 1);
}
