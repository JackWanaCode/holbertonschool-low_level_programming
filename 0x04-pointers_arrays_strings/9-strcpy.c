#include <stdio.h>
#include "holberton.h"

/**
 * _strcpy - Entry point
 * Description: copy a string to another string.
 * @dest:  str is to be printed after copying.
 * @src: source of string
 *
 * Return: no return.
 */
char *_strcpy(char *dest, char *src)
{
	int i;

	for (i = 0; *(src + i) != '\0'; i++)
	{
		*(dest + i) = *(src + i);
	}
	*(dest + i) = '\0';
	return (dest);
}
