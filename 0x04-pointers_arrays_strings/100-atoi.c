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
	int biggiest_num = 2147483647;
	int smallest_num = -2147483648;

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

	if (count_minus_sign % 2 == 0)
		for (i = last; i >= first; i--)
		{
			switch (*(s + i))
			{
			case '1':
				if (biggiest_num - (1 * count_figure) >= num)
					num += (1 * count_figure);
				else
					num = biggiest_num;
				break;
			case '2':
				if (biggiest_num - (2 * count_figure) >= num)
					num += (2 * count_figure);
				else
					num = biggiest_num;
				break;
			case '3':
				if (biggiest_num - (3 * count_figure) >= num)
					num += (3 * count_figure);
				else
					num = biggiest_num;
				break;
			case '4':
				if (biggiest_num - (4 * count_figure) >= num)
					num += (4 * count_figure);
				else
					num = biggiest_num;
				break;
			case '5':
				if (biggiest_num - (5 * count_figure) >= num)
					num += (5 * count_figure);
				else
					num = biggiest_num;
				break;
			case '6':
				if (biggiest_num - (6 * count_figure) >= num)
					num += (6 * count_figure);
				else
					num = biggiest_num;
				break;
			case '7':
				if (biggiest_num - (7 * count_figure) >= num)
					num += (7 * count_figure);
				else
					num = biggiest_num;
				break;
			case '8':
				if (biggiest_num - (8 * count_figure) >= num)
					num += (8 * count_figure);
				else
					num = biggiest_num;
				break;
			case '9':
				if (biggiest_num - (9 * count_figure) >= num)
					num += (9 * count_figure);
				else
					num = biggiest_num;
				break;
			}
			count_figure *= 10;
		}
	else
		for (i = last; i >= first; i--)
		{
			switch (*(s + i))
			{
			case '1':
				if (smallest_num + (1 * count_figure) <= num)
					num -= (1 * count_figure);
				else
					num = smallest_num;
				break;
			case '2':
				if (smallest_num + (3 * count_figure) <= num)
					num -= (2 * count_figure);
				else
					num = smallest_num;
				break;
			case '3':
				if (smallest_num + (3 * count_figure) <= num)
					num -= (3 * count_figure);
				else
					num = smallest_num;
				break;
			case '4':
				if (smallest_num + (4 * count_figure) <= num)
					num -= (4 * count_figure);
				else
					num = smallest_num;
				break;
			case '5':
				if (smallest_num + (5 * count_figure) <= num)
					num -= (5 * count_figure);
				else
					num = smallest_num;
				break;
			case '6':
				if (smallest_num + (6 * count_figure) <= num)
					num -= (6 * count_figure);
				else
					num = smallest_num;
				break;
			case '7':
				if (smallest_num + (7 * count_figure) <= num)
					num -= (7 * count_figure);
				else
					num = smallest_num;
				break;
			case '8':
				if (smallest_num + (8 * count_figure) <= num)
					num -= (8 * count_figure);
				else
					num = smallest_num;
				break;
			case '9':
				if (smallest_num + (9 * count_figure) <= num)
					num -= (9 * count_figure);
				else
					num = smallest_num;
				break;
			}
			count_figure *= 10;
		}
	return (num);
}
