#include <stdio.h>
#include "holberton.h"

/**
 * main - Entry point
 * Description: find the highest factor of this f***ing 612852475143
 *
 * Return: 0 Always
 */
int main(void)
{
	long int max, min;
	long int num = 612852475143;
	long int i = 1;

	for (i = 1; max > min; i++)
	{
		if (num % i == 0)
		{
			min = i;
			max = num / i;
		}
	}
	max = min;
	printf("%li\n", max);
	return (0);
}
