#include <stdio.h>
#include "holberton.h"

/**
 * _memset - Entry point
 * Description: fills the first n bytes of the memory area.
 * @s: string that need to be filled.
 * @b: constant byte b that will fill to memory area.
 * @n: n of bytes to be filled.
 *
 * Return: pointer to the memory area s.
 */
char *_memset(char *s, char b, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
		*(s + i) = b;
	return (s);
}
