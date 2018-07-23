#include <stdio.h>
#include <stdlib.h>
#include "holberton.h"

/**
e * malloc_checked - Entry Point
 * @b: spaces needed to allocate
 *
 * Return: nothing
 */
void *malloc_checked(unsigned int b)
{
	void *n;

	if (b == 0)
		return (NULL);
	n = malloc(b);
	if (n == NULL)
		exit(98);
	return (n);
}
