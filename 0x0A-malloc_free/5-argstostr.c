#include "holberton.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * _strlen - Entry point
 * Description: get length of string
 * @s: string will be check
 * Return: length of string.
 */
int _strlen(char *s)
{
	int i;

	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}
/**
 * argstostr - Entry point
 * Description: concatenates all the arguments of your program
 * @ac: number of string
 * @av: strings are passed
 *
 * Return: a new string after concatenating.
 */
char *argstostr(int ac, char **av)
{
	int i, j, k;
	int l = 0;
	char *argv_concat;

	if (ac == 0 || av[1] == NULL)
		return (NULL);
	for (i = 1; i < ac; i++)
	{
		l += _strlen(av[i]) + 1;
	}
	argv_concat = malloc(sizeof(char) * l);
	if (argv_concat == NULL)
		return (NULL);
	for (i = 0, k = 0; i < ac; i++)
	{
		for (j = 0; av[i][j] != '\0'; j++, k++)
			argv_concat[k] = av[i][j];
		argv_concat[k] = '\n';
		k++;
	}
	return (argv_concat);
}
