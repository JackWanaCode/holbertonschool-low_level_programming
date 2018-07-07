#include <stdio.h>
#include "holberton.h"

/**
 * _strcat - Entry point
 * Description: concatenate a string from source to destination.
 * @dest: destination string.
 * @src: source string.
 *
 * Return: dest.
 */
char *_strcat(char *dest, char *src)
{
	int i, j;
	int bool = 1;

	for (i = 0; bool == 1; i++)
	{
		if (*(dest + i) == '\0')
		{
			for (j = 0; *(src + j) != '\0'; j++, i++)
				*(dest + i) = *(src + j);
			*(dest + i) = '\0';
			bool = 0;
		}
	}
	return (dest);
}
