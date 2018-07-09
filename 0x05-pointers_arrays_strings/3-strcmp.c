#include <stdio.h>
#include "holberton.h"

/**
 * _strcmp - Entry point
 * Description: compare 2 string, character by character
 * @s1: first string to be compared.
 * @s2: second string for comparing.
 *
 * Return: equal ? 0 : ascii dif value for the 1st dif numbers.
 */
int _strcmp(char *s1, char *s2)
{
	int i;

	for (i = 0; *(s1 + i) != '\0'; i++)
	{
		if (*(s1 + i) != *(s2 + i))
			return (*(s1 + i) - *(s2 + i));
	}
	if (*(s2 + i) != '\0')
		return (*(s2 + i) * -1);
	return (0);
}
