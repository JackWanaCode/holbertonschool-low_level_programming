#include <stdio.h>

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	char ch = '0';
	int count = 1;

	while (count < 16)
	{
		if ((ch >= '0' && ch <= '9') || (ch >= 'a' && ch <= 'f'))
		{
			putchar(ch);
			count++;
		}
		ch++;
	}
	putchar('\n');
	return (0);
}
