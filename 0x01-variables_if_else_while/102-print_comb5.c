#include <stdio.h>

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	int i, j; /*for running 2 loops. i for first pair, j for second pair*/
	int count = 1; /*for switching between 2 pair of numbers*/
	int temp; /*temporarily variable to get 1st or 2nd pair before putchar*/
	int check = 0; /*to control putchar whitespace or comma_whitespace*/

	for (i = 0; i <= 99; i++)
	{
		for (j = i + 1; j <= 99; j++)
		{
			if (check == 2) /*to put comma*/
			{
				putchar(',');
				check = 1;
			}
			if (check == 1) /*to put white spare*/
			{
				putchar(' ');
				count == 2 ? check = 2 : check;
			}
			if (count == 1) /*to print first pair*/
			{
				temp = i;
				count = 2;
				j--; /*to go backward jump for next pair*/
			}
			else /*to print second pair*/
			{
				temp = j;
				count = 1;
			}
			putchar(temp / 10 + '0');
			putchar(temp % 10 + '0');
			if (check == 0) /*for set check == 1 after 1st pair*/
				check = 1;
		}
	}
	putchar('\n');
	return (0);
}
