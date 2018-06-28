#include <stdio.h>
#include "holberton.h"

/**
 * main - Entry point
 * Description: check FizzBuzz num from 1 to 100;.
 * Fizz for num completly divided by 3, Buzz for 5 and
 * FizzBuzz for both.
 *
 * Return: 0 Always
 */
int main(void)
{
	int i;

	for (i = 1; i <= 100; i++)
	{
		if (i % 15 == 0)
			printf("FizzBuzz");
		else if (i % 3 == 0)
			printf("Fizz");
		else if (i % 5 == 0)
			printf("Buzz");
		else
			printf("%i", i);
		if (i < 100)
			printf(" ");
	}
	printf("\n");
	return (0);
}
