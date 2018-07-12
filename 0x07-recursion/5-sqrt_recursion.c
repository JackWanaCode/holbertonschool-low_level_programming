#include <stdio.h>
#include "holberton.h"

/**
 * root_it - Entry point
 * Description: taking root of number
 * @n: num to be checked
 * @m: value after root
 * Return: nothing
 */
int root_it(int n, int *m)
{
	if (n % *m == 0 && *m == n / *m)
		return;
	else if (*m >= n / 2)
		*m = -1;
	else if (*m < n /2)
	{
		*m = *m + 1;
		root_it(n, m);
	}
}
/**
 * _sqrt_recursion - Entry point
 * Description: take natural root of number
 * @n: number will be checked
 *
 * Return: root if can be root naturally, otherwise -1
 */
int _sqrt_recursion(int n)
{
	int m = 2;
	int root_it(int n, int m);

	if (n < 0)
		return (0);
	else if (n == 0 || n == 1)
		return (n);
	n = root_it(n, &m);
	return (n);
}
