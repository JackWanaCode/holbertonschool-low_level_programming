#include <stdio.h>
#include <stdlib.h>
#include "3-calc.h"

/**
 * op_add - Entry point
 * Description: add 2 numbers
 * @a: 1st num
 * @b: 2nd num
 * Return: sum of 2
 */
int op_add(int a, int b)
{
	return (a + b);
}

/**
 * op_sub - Entry point
 * Description: subtract 2 numbers
 * @a: 1st num
 * @b: 2nd num
 * Return: substract of 2
 */
int op_sub(int a, int b)
{
	return (a - b);
}

/**
 * op_mul - Entry point
 * Description: multiple 2 numbers
 * @a: 1st num
 * @b: 2nd num
 * Return: multiple of 2 num
 */
int op_mul(int a, int b)
{
	return (a * b);
}

/**
 * op_div - Entry point
 * Description: divide 2 numbers
 * @a: 1st num
 * @b: 2nd num
 * Return: divide 2 num
 */
int op_div(int a, int b)
{
	if (b == 0)
	{
		printf("Error\n");
		exit(100);
	}
	return (a / b);
}

/**
 * op_mod - Entry point
 * Description: modular 2 numbers
 * @a: 1st num
 * @b: 2nd num
 * Return: modular 2 num
 */
int op_mod(int a, int b)
{
	if (b == 0)
	{
		printf("Error\n");
		exit(100);
	}
	return (a % b);
}
