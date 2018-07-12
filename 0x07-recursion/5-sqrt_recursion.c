#include <stdio.h>
#include "holberton.h"

/**
 * root_it - Entry point
 * Description: taking root of number
 * @n: num to be checked
 * @m: check result
 * Return: return m if root, else -1
 */
int root_it(int n, int m)
{
	if (n % m == 0 && n / m == m)
		return (m);
	else if (m >= n / 2)
		return (-1);
	root_it(n, m + 1);
	if (m == 0)
		return (m);
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
	n = root_it(n, m);
	return (n);
}
