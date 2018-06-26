#include <stdio.h>
#include "holberton.h"

/**
 * main - Entry point
 * Description: print fibonaci numbers that is under 50
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	int first = 0;
	int second = 1;
	int fibnum = 1;

	putchar(fibnum + '0');
	while (fibnum < 50)
	{
		printf(", %i", fibnum);
		first = second;
		second = fibnum;
		fibnum = first + second;
	}
	putchar('\n');
	return (0);
}
