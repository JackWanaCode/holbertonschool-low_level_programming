#include <stdio.h>

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	char holberton[] = "Holberton";
	int i = 0;

	while (holberton[i] != '\0')
	{
		putchar(holberton[i]);
		i++;
	}
	putchar('\n');
	return (0);
}
