#include <stdio.h>
#include "holberton.h"

/**
 * _atoi - Entry point
 * Description: takes a string and convert first numbers to integer.
 * @s:  string is to be updated.
 *
 * Return: return if no number or only 0. return number.
 */
int _atoi(char *s)
{
	int i;
	int count_minus_sign = 0;
	int count_figure = 1;
	int first = -1, last = -1;
	int length = 0;
	int num = 0, cmp_num = 0;

	while (*(s + length) != '\0')
	{
		length++;
	}
	for (i = 0; i < length; i++)
	{
		if (*(s + i) >= '0' && *(s + i) <= '9')
		{
			if (first == -1)
				first = i;
			else
				last = i;
		}
		else if (first != -1)
			i = length;
	}
	if (first == -1)
		return (0);
	else if (last == -1)
		last = first;
	for (i = 0; i < first; i++)
	{
		if (*(s + i) == '-')
			count_minus_sign++;
	}
	if (count_minus_sign % 2 == 0)
		for (i = last; i >= first; i--)
		{
			cmp_num = num;
			num += (*(s + i) - '0') * count_figure;
			if (cmp_num > num)
				return (0);
			count_figure *= 10;
		}
	else
		for (i = last; i >= first; i--)
		{
			cmp_num = num;
			num -= (*(s + i) - '0') * count_figure;
			if (cmp_num < num)
				return (0);
			count_figure *= 10;
		}
	return (num);
}
