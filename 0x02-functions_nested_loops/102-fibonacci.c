#include <stdio.h>

/**
 * main - Entry point
 * Description: print fibonaci numbers that is under 50
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	int first = 1;
	int second = 1;
	int fibnum = 2;

	putchar(second + '0');
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
