#include <stdio.h>
#include "holberton.h"

/**
 * main - Entry point
 * Description: print the sum of all the multiple of 3, 5 below 1024
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	int n = 1024;
	int i, j;
	int temp = 0;
	int result_of_3 = 0;
	int result_of_5 = 0;

	for (i = 0; (3 * i) < n; i++)
	{
		temp = i * 3;
		result_of_3 += temp;
	}
	for (j = 0; (5 * j) < n; j++)
	{
		temp = j * 5;
		result_of_5 += temp;
	}
	printf("%i\n", result_of_3 + result_of_5);
	return (0);
}
