#include <stdio.h>
#include "holberton.h"

/**
 * leet - Entry point
 * Description: Convert a string to leet code
 * @s: string to be passed
 *
 * Return: modified s
 */
char *leet(char *s)
{
	char capLet[] = {'A', 'E', 'O', 'T', 'L'};
	char lowLet[] = {'a', 'e', 'o', 't', 'l'};
	int leetCode[] = {'4', '3', '0', '7', '1'};
	int i, j;

	for (i = 0; *(s + i) != '\0'; i++)
	{
		for (j = 0; j < 5; j++)
			if (*(s + i) == capLet[j] || *(s + i) == lowLet[j])
				*(s + i) = leetCode[j];
	}
	return (s);
}
