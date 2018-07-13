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
	if (*s1 == *s2 && *s1 != '\0')
		return (wildcmp((s1 + 1), (s2 + 1)));
	else if (*s2 == '*')
	{
		if (*(s1) == *(s2 + 1))
		{
			return (wildcmp((s1), (s2 + 1)));
		}
		else if (*(s1 + 1) == *(s2 + 1))
			return (wildcmp((s1 + 1), (s2 + 1)));
		else if (*s1 == '\0')
		{
			if (*(s2 + 1) == '\0')
				return (1);
			else if (*(s2 + 1) == '*')
				return (wildcmp(s1, (s2 + 1)));
			else if (*(s1 - 1) == *(s2 + 1))
				return (1);
			else
				return (wildcmp(s1, (s2 + 1)));
		}
		else
			return (wildcmp((s1 + 1), s2));
	}
	else if (*s1 != *s2)
		return (0);
	else if (*s1 == '\0' && *s2 != '\0')
		return (0);
	else if (*s2 == '\0' && *s1 != '\0')
		return (0);
	return (1);
}
