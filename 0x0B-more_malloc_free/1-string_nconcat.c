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
	unsigned int i, l, l1, l2, k;

	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";
	for (l1 = 0; s1[l1] != '\0'; l1++)
		;
	for (l2 = 0; s2[l2] != '\0'; l2++)
		;
	if (l2 >= n)
		l = l1 + n + 1;
	else
		l = l1 + l2 + 1;
	s = malloc(sizeof(char) * l);
	if (s == NULL)
		return (NULL);
	for (i = 0; i < l1; i++)
	{
		s[i] = s1[i];
	}
	for (k = 0; k + l1 + 1 < l; i++, k++)
	{
		s[i] = s2[k];
	}
	s[i] = '\0';
	return (s);
}
