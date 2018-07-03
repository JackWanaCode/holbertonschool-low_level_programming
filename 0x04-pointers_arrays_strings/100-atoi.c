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
	int i, last_digit = 0;
	int count_minus_sign = 0;
	int count_figure = 1;
	int first = -1, last = -1;
	int length = 0;
	int num = 0;

	while (*(s + length) != '\0')
	{
		length++;
	}
	for (i = 0; i < length; i++)
	{
		if (*(s + i) >= '0' && *(s + i) <= '9')
		{
			if (first == -1)
			{
				first = i;
			}
			else
				last = i;
		}
		else if (last != -1)
		{
			i = length;
		}
	}
	if (first == -1)
		return (0);

	for (i = 0; i < first; i++)
	{
		if (*(s + i) == '-')
			count_minus_sign++;
	}
	for (i = last; i >= first; i--)
	{
		switch (*(s + i))
		{
		case '1':
			num += (1 * count_figure);
			break;
		case '2':
			num += (2 * count_figure);
			break;
		case '3':
			num += (3 * count_figure);
			break;
		case '4':
			num += (4 * count_figure);
			break;
		case '5':
			num += (5 * count_figure);
			break;
		case '6':
			num += (6 * count_figure);
			break;
		case '7':
			num += (7 * count_figure);
			break;
		case '8':
			num += (8 * count_figure);
			break;
		case '9':
			num += (9 * count_figure);
			break;
		}
		count_figure *= 10;
		if (last_digit == 0)
		{
			last_digit = num;
			num = 0;
		}
	}
	if (count_minus_sign % 2 != 0)
		num = (num * -1) - last_digit;
	else
		num = num + last_digit;
	return (num);
}
