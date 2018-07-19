#include <stdio.h>
#include <stdlib.h>
#include "holberton.h"

/**
 * string_nconcat - Entry Point
 * @s1: first string.
 * @s2: second string.
 * @n: spaces from s2 needed to allocate
 *
 * Return: nothing
 */
char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	char *s;
	unsigned int i, l, k;

	for (i = 0; s1[i] != '\0'; i++)
		;
	l = i + n + 1;
	s = malloc(sizeof(char) * l);
	if (s == NULL)
		return (NULL);
	for (i = 0; s1[i] != '\0' && s1 != NULL; i++)
	{
		s[i] = s1[i];
	}
	for (k = 0; k < n && s2[k] != '\0' && s2 != NULL; i++, k++)
	{
		s[i] = s2[k];
	}
	while (i <= l)
		s[i++] = '\0';
	return (s);
}
