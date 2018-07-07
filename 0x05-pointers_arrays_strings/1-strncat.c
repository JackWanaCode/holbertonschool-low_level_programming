#include <stdio.h>
#include "holberton.h"

/**
 * _strncat - Entry point
 * Description: concatenate a string from source to destination.
 * @dest: destination string.
 * @src: source string.
 * @n: number of bytes will be concat.
 *
 * Return: dest.
 */
char *_strncat(char *dest, char *src, int n)
{
	int i, j;
	int bool = 1;

	for (i = 0; bool == 1; i++)
	{
		if (*(dest + i) == '\0')
		{
			for (j = 0; j < n; j++, i++)
			{
				if (*(src + j) != '\0')
					*(dest + i) = *(src + j);
				else
					j = n;
			}
			*(dest + i) = '\0';
			bool = 0;
		}
	}
	return (dest);
}
