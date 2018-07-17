#include <stdio.h>
#include <stdlib.h>
#include "holberton.h"

/**
 * create_array - Entry point
 * Description: create an array and initializes it with a specific char
 * @size: size of array
 * @c: character that will be copied.
 *
 * Return: a pointer of array.
 */
char *create_array(unsigned int size, char c)
{
	unsigned int i = 0;
	char *array = malloc(sizeof(char) * size);

	if (array == NULL)
	{
		return (NULL);
	}
	while (i < size)
	{
		array[i] = c;
		i++;
	}
	return (array);
}
