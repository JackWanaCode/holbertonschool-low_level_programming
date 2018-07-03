#include <stdio.h>
#include "holberton.h"

/**
 * swap_int - Entry point
 * Description: takes 2 pointers and swaps their value.
 * @a:  pointer a is to be updated.
 * @b: pointer b is to be updated.
 *
 * Return: no return.
 */
void swap_int(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}
