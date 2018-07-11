#include <stdio.h>
#include "holberton.h"

/**
 * _strstr - Entry point
 * Description: find substring in the other string.
 * @haystack: Other string
 * @needle: substring will be checked
 *
 * Return: return 1st occurence in string if match otherwise return NULL.
 */
char *_strstr(char *haystack, char *needle)
{
	int i, j;

	if (*needle == '\0')
		return (haystack);
	for (i = 0; *(haystack + i) != '\0'; i++)
	{
		for (j = 0; *(needle + j) != '\0'; j++)
		{
			if (*(haystack + i) == *(needle + j))
			{
				while (*(haystack + i + j) == *(needle + j))
				{
					if (*(needle + j + 1) == '\0')
						return (haystack + i);
					j++;
				}
			}
		}
	}
	return (NULL);
}
