#include <stdio.h>
#include "holberton.h"

/**
 * _pow_recursion - Entry point
 * Description: use recursion to calculate a power
 * @x: base num
 * @y: power num
 * Return: num after power
 */
int _pow_recursion(int x, int y)
{
	int n = 1;

	if (y < 0)
		return (-1);
	else if (y == 0)
		n = 1;
	else
		n = x * _pow_recursion(x, y - 1);
	return (n);
}
