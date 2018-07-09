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
	char str[] = "ABCDEFGHIJKLMabcdefghijklmNOPQRSTUVWXYZnopqrstuvwxyz";

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
