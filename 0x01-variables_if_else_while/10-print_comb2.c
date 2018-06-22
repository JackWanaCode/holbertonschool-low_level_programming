#include <stdio.h>

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	int i, j;
	int count = 1;

	for (i = '0'; i <= '9'; i++)
	{
		for (j = '0'; j <= '9'; j++)
		{
			putchar(i);
			putchar(j);
			if (count < 100)
			{
				putchar(',');
				putchar(' ');
				count++;
			}
		}
	}
	putchar('\n');
	return (0);
}
