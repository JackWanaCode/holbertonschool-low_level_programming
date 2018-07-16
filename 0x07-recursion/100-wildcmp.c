#include <stdio.h>
#include "holberton.h"

/**
 * wildcmp - Entry point
 * Description: check wildcard to compare 2 strings
 * @s1: string 1
 * @s2: string 2
 *
 * Return: 1 if true, otherwiser 0
 */
int wildcmp(char *s1, char *s2)
{
	if (*s1 == '\0' && *s2 == '\0')
	{
		return (1);
	}
	if (*s1 == *s2)
	{
		return (wildcmp(s1 + 1, s2 + 1));
	}
	if (*s2 == '*')
	{
		if (wildcmp(s1, s2 + 1) > 0)
		{
			return (1);
		}
		if (wildcmp(s1 + 1, s2) > 0)
		{
			return (1);
		}
	}
	return (0);
}
