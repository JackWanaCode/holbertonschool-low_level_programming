#include <stdio.h>
#include <limits.h>
#include "holberton.h"


/**
 * get_endianness - Entry point
 * Description: checks the endianness
 * Return: 1 if it is Litthe Endian, -1 if Big Endian.
 */
int get_endianness(void)
{
	int n = 1;

	if (*(char *)&n)
		return (1);
	else
		return (0);
}
