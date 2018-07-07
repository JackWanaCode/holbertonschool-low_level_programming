#include <stdio.h>
#include "holberton.h"

/**
 * rot13 - Entry point
 * Description: convert to rot13 code
 * @s: string to be passed
 *
 * Return: modified s
 */
char *rot13(char *s)
{
	int i, j, k;
	int str[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', \
'K', 'L', 'M', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', \
'j', 'k', 'l', 'm', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', \
'V', 'W', 'X', 'Y', 'Z', 'n', 'o', 'p', 'q', 'r', 's', 't', \
'u', 'v', 'w', 'x', 'y', 'z'};

	for (i = 0; *(s + i) != '\0'; i++)
	{
		for (j = 0; j < 52; j++)
		{
			if (*(s + i) == str[j])
			{
				k = (j + 26) % 52;
				*(s + i) = str[k];
				j = 52;
			}
		}
	}
	return (s);
}
