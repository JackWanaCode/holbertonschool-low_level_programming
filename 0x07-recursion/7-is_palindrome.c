#include <stdio.h>
#include "holberton.h"

/**
 * len - Entry point
 * Description: get len of sring to pointer point to
 * @s: pointer pointing to a string
 *
 * Return: length
 */
int len(char *s)
{
	int i = 0;

	if (*s != '\0')
		i = 1 + len(s + 1);
	else
		return (0);
	return (i);
}
/**
 * check_pal - Entry point
 * Description: help to check palidrome
 * @s: pointer pointing to a string
 * @i: start point of string
 * @z: end point of string
 *
 * Return: 1 if palidrome, else 0
 */
int check_pal(char *s, int i, int z)
{
	if (s[i] != s[z])
		return (0);
	else if (i >= z)
		return (1);
	else
		return (check_pal(s, i + 1, z - 1));
}
/**
 * is_palindrome - Entry point
 * Description: check palidrome
 * @s: pointer pointing to a string
 *
 * Return: 1 if palidrome, else 0
 */
int is_palindrome(char *s)
{
	int i = 0;
	int z;

	z = len(s) - 1;
	return (check_pal(s, i, z));
}
