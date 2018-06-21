#include <stdio.h>

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	char ch = 'a';
	int count = 0;

	while (count < 52)
	{
		if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z'))
		{
			putchar(ch);
			count++;
		}
		ch = (ch + 1) % 123;
	}
	putchar('\n');
	return (0);
}
