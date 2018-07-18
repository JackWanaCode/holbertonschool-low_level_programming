#include <stdio.h>
#include <stdlib.h>


int _strlen(char *s)
{
	int i;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}


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
	dup_str = malloc(sizeof(char) * i + 1);
	if (dup_str == NULL)
	{
		return (NULL);
	}
	if (str[0] != ' ')
	{
		dup_str[0] = str[0];
	}
	k = 1;
	while (k < i)
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

char **argstostr(int h, char *str)
{
	int i, j = 0, k = 0;
	char **array_of_str;

	array_of_str = malloc(sizeof(char) * (h + 1));
	if (array_of_str == NULL)
	{
		return (NULL);
	}
	for (i = 0; i <= h; i++)
	{
		for (k = 0; str[j] != ' '; j++)
		{
			k++;
		}
		array_of_str[i] = malloc(sizeof(char) * k + 1);
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
	array_of_str[i] = '\0';
	return (array_of_str);
}

char **strtow(char *str)
{
	int h, l;
	char *re_str = NULL;
	char **restr = NULL;

	re_str = _strmod(str, &h, &l);
	restr = argstostr(h, re_str);
	free(re_str);
	return (restr);
}
