#include <stdio.h>
#include "holberton.h"

/**
 * _strncpy - Entry point
 * Description: concatenate a string from source to destination.
 * @dest: destination string.
 * @src: source string.
 * @n: number of bytes.
 *
 * Return: dest.
 */
char *_strncpy(char *dest, char *src, int n)
{
	int i;

	for (i = 0; i < n; i++)
	{
		if (*(src + i) != '\n')
		{
			*(dest + i) = *(src + i);
		}
		else
			i = n;
	}
	return (dest);
}
