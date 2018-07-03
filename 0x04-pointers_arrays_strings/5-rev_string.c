#include <stdio.h>
#include "holberton.h"

/**
 * rev_string - Entry point
 * Description: reverse a string.
 * @s:  str is to be printed.
 *
 * Return: no return.
 */
void rev_string(char *s)
{
	int i = 0, j;
	int length = 0;
	int temp;

	while (*(s + length) != '\0')
		length++;
	j = length - 1;
	while (i < length / 2)
	{
		temp = *(s + i);
		*(s + i) = *(s + j);
		*(s + j) = temp;
		i++;
		j--;
	}
	*(s + length) = '\0';
}
