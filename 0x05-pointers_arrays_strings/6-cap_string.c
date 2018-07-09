#include <stdio.h>
#include "holberton.h"

/**
 * cap_string - Entry point
 * Description: Capitalize word and separate by other charaters
 * @s: string to be passed
 *
 * Return: modified s
 */
char *cap_string(char *s)
{
	char string[] = " \t\v\n,.!?\"(){}";
	int i, j;

	for (i = 1; *(s + i) != '\0'; i++)
	{
		if (*(s + i) == '\t')
			*(s + i) = ' ';
		if (*(s + i) >= 'a' && *(s + i) <= 'z')
		{
			for (j = 0; *(string + j) != '\0'; j++)
			{
				if (*(string + j) == *(s + i - 1))
					*(s + i) -= 32;
				else if (*(s + i - 1) == ';')
					*(s + i) -= 32;
			}
		}
	}
	return (s);
}
