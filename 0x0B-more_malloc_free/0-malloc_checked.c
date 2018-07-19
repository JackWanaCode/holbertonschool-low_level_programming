#include <stdio.h>
#include <stdlib.h>
#include "holberton.h"
#include <limits.h>

/**
 * malloc_checked - Entry Point
 * @b: spaces needed to allocate
 *
 * Return: nothing
 */
void *malloc_checked(unsigned int b)
{
	unsigned int *n;

	n = malloc(sizeof(unsigned int) * b);
	if (n == NULL)
		exit(98);
	return (n);
}
