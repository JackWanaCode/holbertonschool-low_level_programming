#include <stdio.h>
#include <stdlib.h>
#include "holberton.h"

/**
 * _strlen - Entry point
 * Description: returns length of a string
 * @s: input string to count
 * Return: length of string
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
 * _strmod - Entry point.
 * Description: modify the string
 * @str: string to be checked
 * @h: 1st dimenstion of string
 * @l: length of the string
 * Return: a new string that splitted by space.
 */
char *_strmod(char *str, int *h, int *l)
{
	int i = 0, j = 0, k = 0;
	char *dup_str = NULL;

	if (str == NULL)
		return (NULL);
	while (str[i])
	{
		i++;
	}
	if (str[i - 1] != ' ')
		*h = 1;
	dup_str = malloc(sizeof(char) * i + 1);
	if (dup_str == NULL)
	{
		return (NULL);
	}
	if (str[0] != ' ')
	{
		dup_str[0] = str[0];
		j++;
	}
	k = 1;
	while (str[k] != '\0')
	{
		if (str[k] != ' ')
		{
			dup_str[j] = str[k];
			j++;
			k++;
		}
		else if (str[k] == ' ' && str[k - 1] != ' ')
		{
			dup_str[j] = ' ';
			k++;
			j++;
			*h = *h + 1;
		}
		else
		k++;
	}
	*l = j;
	while (j < i)
		dup_str[j++] = '\0';
	return (dup_str);
}

/**
 * argstostr1 - Entry point.
 * Descrition: return a double pointer to a 2d array
 * @h: number of rows
 * @str: string to checked
 * Return: 2d array
 */
char **argstostr1(int h, char *str)
{
	int i, j = 0, k = 0;
	char **array_of_str;

	array_of_str = malloc(sizeof(char *) * h);
	if (array_of_str == NULL)
	{
		return (NULL);
	}
	for (i = 0; i <= h; i++)
	{
		for (k = 0; str[j] != ' ' && i < h; j++)
		{
			k++;
		}
		if (i == h)
			k = 0;
		array_of_str[i] = malloc(sizeof(char) * (k + 1));
		if (array_of_str[i] == NULL)
		{
			while (i >= 0)
			{
				free(array_of_str[i]);
				i--;
			}
			free(array_of_str);
			return (NULL);
		}
		j++;
	}
	j = 0;
	for (i = 0; i < h; i++)
	{
		for (k = 0; str[j] != ' '; k++, j++)
		{
			array_of_str[i][k] = str[j];
		}
		array_of_str[i][k] = '\0';
		j++;
	}
	array_of_str[i] = NULL;
	return (array_of_str);
}

/**
 * strtow - Entry Point
 * Description: split a given string and convert it to new 2d array.
 * @str: input string
 * Return: pointer to pointer to 2d array
 */
char **strtow(char *str)
{
	int h = 0, l = 0;
	char *re_str = NULL;
	char **restr = NULL;

	if (!str || !*str)
		return (NULL);
	re_str = _strmod(str, &h, &l);
	restr = argstostr1(h, re_str);
	return (restr);
}
