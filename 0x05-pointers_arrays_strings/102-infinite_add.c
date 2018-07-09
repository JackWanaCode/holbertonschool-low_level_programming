#include "holberton.h"

/**
 * add2char - Entry point
 * Description: plus 2 number character
 * @c1: first num char
 * @c2: second num char
 * @ret: return value in single num character
 * @m: value to remember after plus
 *
 * Return: nothing
 */
void add2char(char *c1, char *c2, int *ret, int *m)
{
	*ret = *c1 - '0' + *c2 - '0';
	*m = *ret / 10;
	*ret = *ret % 10;
}
/**
 * infinite_add - Entry point
 * Description: plus 2 number strings
 * @n1: first string
 * @n2: second string
 * @r: return string of value
 * @size_r: length of r
 *
 * Return: r
 */
char *infinite_add(char *n1, char *n2, char *r, int size_r)
{
	int i, cut;
	int l_of_n1, l_of_n2;
	int m1 = 0, m2 = 0, overFlow = 0, ret = 0;
	char zero = '0';
	char ret_char[size_r];

	for (l_of_n1 = 0; *(n1 + l_of_n1) != '\0'; l_of_n1++)
	{}
	for (l_of_n2 = 0; *(n2 + l_of_n2) != '\0'; l_of_n2++)
	{}
	l_of_n1--;
	l_of_n2--;
	for (i = size_r - 1; i >= 0; i--)
	{
		m2 = 0;
		ret = 0;
		overFlow = 0;
		if (l_of_n1 >= 0 && l_of_n2 >= 0)
			add2char((n1 + l_of_n1), (n2 + l_of_n2), &ret, &m2);
		else if (l_of_n1 < 0 && l_of_n2 >= 0)
			add2char(&zero, (n2 + l_of_n2), &ret, &m2);
		else if (l_of_n1 >= 0 && l_of_n2 < 0)
			add2char((n1 + l_of_n1), &zero, &ret, &m2);
		else if (l_of_n1 < 0 && l_of_n2 < 0)
			add2char(&zero, &zero, &ret, &m2);
		ret = ret + m1;
		if (ret > 9)
		{
			ret = 0;
			overFlow = 1;
		}
		ret_char[i] = ret + '0';
		m1 = m2 + overFlow;
		if (ret == 0 && m1 == 0)
		{
			cut = i + 1;
			i = -1;
		}
		else if (i == 0 && m1 != 0)
			return (0);
		else if (i == 0 && (l_of_n1 != 0 || l_of_n2 != 0))
			return (0);
		l_of_n1--;
		l_of_n2--;
	}
	for (i = 0; i < size_r - 1; i++)
		*(r + i) = *(ret_char + i + cut);
	*(r + i) = '\0';
	return (r);
}
