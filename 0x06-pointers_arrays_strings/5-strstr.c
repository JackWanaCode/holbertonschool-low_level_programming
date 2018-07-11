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
	for (i = 0; *(needle + i) != '\0'; i++)
	{
		for (j = 0; *(haystack + j) != '\0'; j++)
		{
			if (*(needle + i) == *(haystack + j))
			{
				if (*(needle + i + 1) == '\0')
					return (haystack + j - i);
				else if (needle[i + 1] != haystack[j + 1])
					return (NULL);
				i++;
			}
		}
	}
	return (NULL);
}
