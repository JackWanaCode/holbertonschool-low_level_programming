#include <stdio.h>
#include <stdlib.h>
#include "holberton.h"

/**
 * _calloc - Entry Point
 * @nmemb: number of element(s) in array
 * @size: size of each element.
 *
 * Return: a pointer to array of zero
 */
void *_calloc(unsigned int nmemb, unsigned int size)
{
	char *c = NULL;
	unsigned int i = 0;

	if (nmemb == 0 || size == 0)
	{
		nmemb = 1;
		size = 1;
	}
	c = malloc(nmemb * size);
	if (c == NULL)
		return (NULL);
	while (i < nmemb)
		c[i++] = 0;
	return (c);
}
