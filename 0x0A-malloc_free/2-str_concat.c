#include <stdio.h>
#include <stdlib.h>
#include "holberton.h"

/**
 * strcp - Entry point
 * Description: copy s1 to dest.
 * @dest: destination
 * @s: string to be copied.
 * @empty_str: if s is NULL, concat empty string to dest.
 * Return: a pointer to new string
 */
void strcp(char *dest, char *s, char *empty_str)
{
	if (s == NULL)
		*dest = *empty_str;
	else
	{
		while (*s != '\0')
		{
			*dest++ = *s++;
		}
	}
}

/**
 * str_concat - Entry point
 * Description: make a new string that concat from s1 and s2
 * @s1: first string to be concatted.
 * @s2: second string to be concatted.
 * Return: a pointer to new string
 */
char *str_concat(char *s1, char *s2)
{
	int i = 0, j = 0;
	char *empty_str = "";
	char *str_cc = NULL;

	if (s1 != NULL)
	{
		while (s1[i])
		{
			i++;
		}
	}
	if (s2 != NULL)
	{
		while (s2[j])
		{
			j++;
		}
	}
	str_cc = malloc(sizeof(char) * (i + j) + 1);
	if (str_cc == NULL)
	{
		return (NULL);
	}
	strcp(str_cc, s1, empty_str);
	strcp(str_cc + i, s2, empty_str);
	str_cc[i + j] = '\0';
	return (str_cc);
}
