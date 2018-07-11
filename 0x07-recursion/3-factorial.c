#include <stdio.h>
#include "holberton.h"

/**
 * factorial - Entry point
 * Description: use recursion to calculate factorial of n
 * @n: n will be calculated
 *
 * Return: fact of n
 */
int factorial(int n)
{
	int ret;

	if (n < 0)
		return (-1);
	else if (n == 0 || n == 1)
		ret = 1;
	else
		ret = n * factorial(n - 1);
	return (ret);
}
