#include <stdio.h>
#include <stdlib.h>
#include "holberton.h"

/**
 * _strdup - Entry point
 * Description: Use malloc to duplicate a string
 * @str: string to be duplicated
  *
 * Return: a dublicated string.
 */
char *_strdup(char *str)
{
	int i = 0;
	char *dup_str = NULL;

	while (str[i])
	{
		i++;
	}
	dup_str = malloc(sizeof(char) * i + 1);
	if (dup_str == NULL)
		return (NULL);
	while (i >= 0)
	{
		dup_str[i] = str[i];
		i--;
	}
	return (dup_str);
}
