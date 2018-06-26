#include <stdio.h>

/**
 * main - Entry point
 * Description: print fibonaci numbers that is under 50
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	float first = 1;
	float second = 1;
	float fibnum = 2;
	int count = 0;

	putchar(second + '0');
	while (count < 49)
	{
		printf(", %.0f", fibnum);
		first = second;
		second = fibnum;
		fibnum = first + second;
		count++;
	}
	putchar('\n');
	return (0);
}
